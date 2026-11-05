package dev.sporeport.cellstage;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.RectF;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

import java.util.ArrayList;
import java.util.List;

public final class CellStageView extends View {
    private enum Screen {
        SETUP,
        GAME,
        EDITOR
    }

    private enum Diet {
        HERBIVORE,
        CARNIVORE,
        OMNIVORE
    }

    private enum FoodKind {
        ALGAE,
        MEAT,
        PART
    }

    private static final int FOOD_COUNT = 12;
    private static final float PLAYER_RADIUS = 30f;
    private static final float PLAYER_SPEED = 420f;
    private static final float PLAYER_ACCELERATION = 900f;
    private static final int FOOD_PER_GROWTH_LEVEL = 4;
    private static final float FOOD_RESPAWN_SECONDS = 1.5f;
    private static final long FRAME_DELAY_MS = 16L;
    private static final String SAVE_PREFERENCES = "cell_stage_session";
    private static final int SAVE_VERSION = 2;
    private static final String TAG = "CellStageView";

    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final RectF primaryButton = new RectF();
    private final RectF secondaryButton = new RectF();
    private final List<Food> food = new ArrayList<>();
    private final HandlerFrameClock frameClock = new HandlerFrameClock();

    private Screen screen = Screen.SETUP;
    private float playerX;
    private float playerY;
    private float targetX;
    private float targetY;
    private float velocityX;
    private float velocityY;
    private float radius;
    private float density;
    private float lastFrameSeconds;
    private float foodSpawnSeconds;
    private long lastFrameNanos;
    private int nutrientsCollected;
    private int partsCollected;
    private int addedParts;
    private int difficulty = 1;
    private Diet diet = Diet.CARNIVORE;
    private boolean hasPosition;
    private boolean running;
    private SavedSession pendingRestore;
    private long randomState = 31L;

    public CellStageView(Context context) {
        super(context);
        density = getResources().getDisplayMetrics().density;
        pendingRestore = loadSession(context.getSharedPreferences(
                SAVE_PREFERENCES, Context.MODE_PRIVATE));
        setFocusable(true);
    }

    @Override
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();
        resumeGameLoop();
    }

    @Override
    protected void onDetachedFromWindow() {
        pauseGameLoop();
        super.onDetachedFromWindow();
    }

    public void pauseGameLoop() {
        running = false;
        removeCallbacks(frameClock);
        saveSession();
    }

    public void resumeGameLoop() {
        if (!running && isAttachedToWindow()) {
            running = true;
            lastFrameNanos = 0L;
            if (screen == Screen.GAME) {
                postOnAnimation(frameClock);
            }
        }
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        float width = getWidth();
        float height = getHeight();
        if (width <= 0f || height <= 0f) {
            return;
        }
        radius = PLAYER_RADIUS * density * playerGrowthScale();

        drawBackground(canvas, width, height);
        if (screen == Screen.SETUP) {
            drawSetup(canvas, width, height);
        } else if (screen == Screen.GAME) {
            drawGame(canvas, width, height);
        } else {
            drawEditor(canvas, width, height);
        }
    }

    @Override
    protected void onSizeChanged(int width, int height, int oldWidth, int oldHeight) {
        super.onSizeChanged(width, height, oldWidth, oldHeight);
        if (pendingRestore != null && width > 0 && height > 0) {
            restoreSession();
        }
    }

    private void drawBackground(Canvas canvas, float width, float height) {
        canvas.drawColor(0xFF071624);
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(0xFF0B2030);
        canvas.drawCircle(width * 0.5f, height * 0.54f, Math.max(width, height) * 0.62f, paint);

        paint.setColor(0x24366D82);
        for (int i = 0; i < 18; i++) {
            float x = ((i * 97f) % 997f) / 997f * width;
            float y = ((i * 173f + 41f) % 991f) / 991f * height;
            float bubbleRadius = (5f + (i % 4) * 3f) * density;
            canvas.drawCircle(x, y, bubbleRadius, paint);
        }
    }

    private void drawSetup(Canvas canvas, float width, float height) {
        drawTitle(canvas, width, height, "Começar no oceano");
        drawText(canvas, "Escolha a dieta e a dificuldade da sua célula.", width * 0.5f,
                height * 0.22f, 16f, 0xFFADC5CF, Paint.Align.CENTER);

        float cardWidth = Math.min(width * 0.29f, 160f * density);
        float cardHeight = 108f * density;
        float cardY = height * 0.36f;
        float gap = 14f * density;
        float totalWidth = cardWidth * 3f + gap * 2f;
        float left = (width - totalWidth) * 0.5f;
        RectF herbivore = new RectF(left, cardY, left + cardWidth, cardY + cardHeight);
        RectF carnivoreCard = new RectF(left + cardWidth + gap, cardY,
                left + cardWidth * 2f + gap, cardY + cardHeight);
        RectF omnivoreCard = new RectF(left + cardWidth * 2f + gap * 2f, cardY,
                left + totalWidth, cardY + cardHeight);
        drawCard(canvas, herbivore, diet == Diet.HERBIVORE,
                "Herbívora", "Algas", 0xFF77C776);
        drawCard(canvas, carnivoreCard, diet == Diet.CARNIVORE,
                "Carnívora", "Carne", 0xFFFF9A65);
        drawCard(canvas, omnivoreCard, diet == Diet.OMNIVORE,
                "Onívora", "Algas e carne", 0xFFFFD166);
        secondaryButton.set(width * 0.5f - 115f * density, height * 0.59f,
                width * 0.5f + 115f * density, height * 0.59f + 46f * density);
        drawButton(canvas, secondaryButton, "Dificuldade: " + difficultyName(), 0xFF394E65);
        primaryButton.set(width * 0.5f - 115f * density, height * 0.72f,
                width * 0.5f + 115f * density, height * 0.72f + 54f * density);
        drawButton(canvas, primaryButton, "Entrar na água", 0xFF218C9A);
        drawText(canvas, "Arte e regras temporárias do protótipo", width * 0.5f,
                height * 0.92f, 12f, 0xFF7995A1, Paint.Align.CENTER);
    }

    private void drawGame(Canvas canvas, float width, float height) {
        float zoom = cameraZoom();
        canvas.save();
        canvas.translate(width * 0.5f - playerX * zoom,
                height * 0.5f - playerY * zoom);
        canvas.scale(zoom, zoom);
        for (Food item : food) {
            drawFood(canvas, item);
        }
        drawPlayer(canvas, playerX, playerY);
        canvas.restore();

        drawText(canvas, "Oceano primordial", 20f * density, 34f * density,
                19f, 0xFFE9F4F7, Paint.Align.LEFT);
        drawText(canvas, "Alimento: " + nutrientsCollected + "     Partes: " + partsCollected +
                        "     Crescimento: " + (growthLevel() + 1) + "/5",
                20f * density, 61f * density, 14f, 0xFFADC5CF, Paint.Align.LEFT);
        drawText(canvas, "Dieta: " + dietName() + "  Alimentos no campo: " + food.size(),
                20f * density, 84f * density, 10f, 0xFF7995A1, Paint.Align.LEFT);
        drawText(canvas, "Toque e arraste para nadar", width * 0.5f, height * 0.12f,
                14f, 0xFFADC5CF, Paint.Align.CENTER);

        float buttonHeight = 54f * density;
        primaryButton.set(width * 0.5f - 125f * density, height - buttonHeight - 22f * density,
                width * 0.5f + 125f * density, height - 22f * density);
        drawButton(canvas, primaryButton, "Chamar parceira • editar", 0xFF216F93);
        drawText(canvas, "Protótipo: explore e recolha os pontos brilhantes",
                width * 0.5f, primaryButton.top - 15f * density, 12f, 0xFF7995A1,
                Paint.Align.CENTER);
    }

    private void drawEditor(Canvas canvas, float width, float height) {
        drawTitle(canvas, width, height, "Editor da célula");
        drawText(canvas, "Peças experimentais: " + addedParts, width * 0.5f,
                height * 0.2f, 15f, 0xFFADC5CF, Paint.Align.CENTER);

        float centerX = width * 0.5f;
        float centerY = height * 0.47f;
        float bodyRadius = Math.min(width, height) * 0.14f;
        drawPlayer(canvas, centerX, centerY, bodyRadius, addedParts);
        drawText(canvas, "Adicione uma peça para testar o editor", centerX,
                centerY + bodyRadius + 37f * density, 14f, 0xFFADC5CF, Paint.Align.CENTER);

        float buttonWidth = Math.min(width * 0.78f, 290f * density);
        float left = centerX - buttonWidth * 0.5f;
        float top = height * 0.68f;
        primaryButton.set(left, top, left + buttonWidth, top + 52f * density);
        drawButton(canvas, primaryButton, "Adicionar peça", 0xFF218C9A);
        secondaryButton.set(left, top + 66f * density, left + buttonWidth,
                top + 118f * density);
        drawButton(canvas, secondaryButton, "Voltar a nadar", 0xFF394E65);
        drawText(canvas, "Somente formas provisórias, sem recursos do jogo",
                centerX, height * 0.91f, 12f, 0xFF7995A1, Paint.Align.CENTER);
    }

    private void drawTitle(Canvas canvas, float width, float height, String title) {
        drawText(canvas, title, width * 0.5f, height * 0.13f, 24f,
                0xFFE9F4F7, Paint.Align.CENTER);
    }

    private String difficultyName() {
        if (difficulty == 0) {
            return "Fácil";
        }
        return difficulty == 1 ? "Normal" : "Difícil";
    }

    private String dietName() {
        switch (diet) {
            case HERBIVORE:
                return "Herbívora";
            case OMNIVORE:
                return "Onívora";
            default:
                return "Carnívora";
        }
    }

    private void drawCard(Canvas canvas, RectF bounds, boolean selected, String title,
                          String subtitle, int color) {
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(selected ? 0xFF1C3C4B : 0xFF102A3A);
        canvas.drawRoundRect(bounds, 16f * density, 16f * density, paint);
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(2f * density);
        paint.setColor(selected ? color : 0xFF29485A);
        canvas.drawRoundRect(bounds, 16f * density, 16f * density, paint);
        drawText(canvas, title, bounds.centerX(), bounds.top + 38f * density,
                17f, color, Paint.Align.CENTER);
        drawText(canvas, subtitle, bounds.centerX(), bounds.top + 69f * density,
                12f, 0xFFADC5CF, Paint.Align.CENTER);
        drawText(canvas, selected ? "Selecionada" : "Toque para escolher",
                bounds.centerX(), bounds.bottom - 15f * density,
                11f, 0xFF7995A1, Paint.Align.CENTER);
    }

    private void drawButton(Canvas canvas, RectF bounds, String label, int color) {
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(color);
        canvas.drawRoundRect(bounds, 18f * density, 18f * density, paint);
        drawText(canvas, label, bounds.centerX(), bounds.centerY() + 6f * density,
                15f, 0xFFF4FAFC, Paint.Align.CENTER);
    }

    private void drawText(Canvas canvas, String text, float x, float y, float sp,
                          int color, Paint.Align align) {
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(color);
        paint.setTextAlign(align);
        paint.setTextSize(sp * density);
        canvas.drawText(text, x, y, paint);
    }

    private void drawFood(Canvas canvas, Food item) {
        int color;
        switch (item.kind) {
            case ALGAE:
                color = 0xFF90DE83;
                break;
            case MEAT:
                color = 0xFFFFA06E;
                break;
            default:
                color = 0xFFC9E6EE;
                break;
        }
        paint.setStyle(Paint.Style.FILL);
        paint.setColor((color & 0x00FFFFFF) | 0x33000000);
        canvas.drawCircle(item.x, item.y, item.radius * 2.2f, paint);
        paint.setColor(color);
        canvas.drawCircle(item.x, item.y, item.radius, paint);
        paint.setColor(0x99FFFFFF);
        canvas.drawCircle(item.x - item.radius * 0.25f, item.y - item.radius * 0.25f,
                item.radius * 0.28f, paint);
    }

    private void drawPlayer(Canvas canvas, float x, float y) {
        drawPlayer(canvas, x, y, radius, addedParts);
    }

    private void drawPlayer(Canvas canvas, float x, float y, float bodyRadius, int parts) {
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(3f * density);
        paint.setStrokeCap(Paint.Cap.ROUND);
        paint.setColor(0xFF79DDD7);
        for (int i = 0; i < 4; i++) {
            float angle = (float) (Math.PI * (i + 1) / 5f);
            float startX = x + (float) Math.cos(angle) * bodyRadius * 0.75f;
            float startY = y + (float) Math.sin(angle) * bodyRadius * 0.75f;
            float endX = x + (float) Math.cos(angle) * bodyRadius * 1.55f;
            float endY = y + (float) Math.sin(angle) * bodyRadius * 1.55f;
            canvas.drawLine(startX, startY, endX, endY, paint);
        }
        for (int i = 0; i < parts; i++) {
            float angle = (float) (i * Math.PI * 2f / Math.max(1, parts));
            float startX = x + (float) Math.cos(angle) * bodyRadius * 0.8f;
            float startY = y + (float) Math.sin(angle) * bodyRadius * 0.8f;
            float endX = x + (float) Math.cos(angle) * bodyRadius * 1.45f;
            float endY = y + (float) Math.sin(angle) * bodyRadius * 1.45f;
            canvas.drawLine(startX, startY, endX, endY, paint);
        }

        paint.setStyle(Paint.Style.FILL);
        paint.setColor(0xFF59D8D0);
        canvas.drawCircle(x, y, bodyRadius, paint);
        paint.setColor(0xFFB7FFF2);
        canvas.drawCircle(x - bodyRadius * 0.22f, y - bodyRadius * 0.24f,
                bodyRadius * 0.2f, paint);
        paint.setColor(0xFF0C4053);
        canvas.drawCircle(x + bodyRadius * 0.36f, y - bodyRadius * 0.12f,
                bodyRadius * 0.12f, paint);
    }

    private void startGame() {
        screen = Screen.GAME;
        hasPosition = false;
        nutrientsCollected = 0;
        partsCollected = 0;
        addedParts = 0;
        velocityX = 0f;
        velocityY = 0f;
        foodSpawnSeconds = 0f;
        populateFood();
        saveSession();
        invalidate();
    }

    private void populateFood() {
        food.clear();
        if (getWidth() <= 0 || getHeight() <= 0) {
            return;
        }
        float width = getWidth();
        float height = getHeight();
        playerX = width * 0.5f;
        playerY = height * 0.58f;
        targetX = playerX;
        targetY = playerY;
        randomState = 31L + diet.ordinal() * 101L;
        for (int i = 0; i < FOOD_COUNT; i++) {
            float x;
            float y;
            int attempts = 0;
            do {
                x = playerX + (nextRandomFloat() - 0.5f) * width * 0.76f;
                y = playerY + (nextRandomFloat() - 0.5f) * height * 0.62f;
                attempts++;
            } while (attempts < 32 && distanceSquared(x, y, playerX, playerY) <
                    radius * radius * 9f);
            FoodKind kind = i % 4 == 0 ? FoodKind.PART : nextFoodKind();
            float itemRadius = (kind == FoodKind.PART ? 9f : 7f) * density;
            food.add(new Food(x, y, itemRadius, kind));
        }
        hasPosition = true;
        if (running) {
            lastFrameNanos = 0L;
            postOnAnimation(frameClock);
        }
    }

    private void updateGame(float deltaSeconds) {
        if (screen != Screen.GAME) {
            return;
        }
        float dx = targetX - playerX;
        float dy = targetY - playerY;
        float distance = (float) Math.sqrt(dx * dx + dy * dy);
        float speedMultiplier = difficulty == 0 ? 1.15f : (difficulty == 2 ? 0.85f : 1f);
        float maxSpeed = PLAYER_SPEED * speedMultiplier * density;
        float acceleration = PLAYER_ACCELERATION * density;
        float desiredSpeed = Math.min(maxSpeed, (float) Math.sqrt(2f * acceleration * distance));
        if (distance <= density * 2f) {
            desiredSpeed = 0f;
        }
        float desiredVelocityX = distance > 0f ? dx / distance * desiredSpeed : 0f;
        float desiredVelocityY = distance > 0f ? dy / distance * desiredSpeed : 0f;
        float velocityDeltaX = desiredVelocityX - velocityX;
        float velocityDeltaY = desiredVelocityY - velocityY;
        float velocityDelta = (float) Math.sqrt(velocityDeltaX * velocityDeltaX +
                velocityDeltaY * velocityDeltaY);
        float maxVelocityDelta = acceleration * deltaSeconds;
        if (velocityDelta > maxVelocityDelta && velocityDelta > 0f) {
            float scale = maxVelocityDelta / velocityDelta;
            velocityDeltaX *= scale;
            velocityDeltaY *= scale;
        }
        velocityX += velocityDeltaX;
        velocityY += velocityDeltaY;
        playerX += velocityX * deltaSeconds;
        playerY += velocityY * deltaSeconds;

        float collectDistance = radius * 0.75f;
        boolean collectedFood = false;
        for (int i = food.size() - 1; i >= 0; i--) {
            Food item = food.get(i);
            if (item.kind != FoodKind.PART && !canEat(item.kind)) {
                continue;
            }
            if (distanceSquared(item.x, item.y, playerX, playerY) <=
                    (collectDistance + item.radius) * (collectDistance + item.radius)) {
                if (item.kind == FoodKind.PART) {
                    partsCollected++;
                } else {
                    nutrientsCollected++;
                }
                food.remove(i);
                collectedFood = true;
            }
        }
        if (collectedFood) {
            saveSession();
        }
        if (food.size() < FOOD_COUNT) {
            foodSpawnSeconds += deltaSeconds;
            if (foodSpawnSeconds >= FOOD_RESPAWN_SECONDS) {
                foodSpawnSeconds = 0f;
                spawnFoodAtViewEdge();
            }
        } else {
            foodSpawnSeconds = 0f;
        }
    }

    private FoodKind nextFoodKind() {
        if (diet == Diet.HERBIVORE) {
            return FoodKind.ALGAE;
        }
        if (diet == Diet.CARNIVORE) {
            return FoodKind.MEAT;
        }
        return nextRandomBoolean() ? FoodKind.ALGAE : FoodKind.MEAT;
    }

    private boolean canEat(FoodKind kind) {
        return kind == FoodKind.PART || diet == Diet.OMNIVORE ||
                (diet == Diet.HERBIVORE && kind == FoodKind.ALGAE) ||
                (diet == Diet.CARNIVORE && kind == FoodKind.MEAT);
    }

    private void spawnFoodAtViewEdge() {
        float zoom = cameraZoom();
        float angle = nextRandomFloat() * (float) (Math.PI * 2.0);
        float halfWidth = getWidth() / (2f * zoom);
        float halfHeight = getHeight() / (2f * zoom);
        float x = playerX + (float) Math.cos(angle) * halfWidth * 1.08f;
        float y = playerY + (float) Math.sin(angle) * halfHeight * 1.08f;
        FoodKind kind = nextRandomInt(4) == 0 ? FoodKind.PART : nextFoodKind();
        float itemRadius = (kind == FoodKind.PART ? 9f : 7f) * density;
        food.add(new Food(x, y, itemRadius, kind));
        saveSession();
    }

    private int growthLevel() {
        return Math.min(4, nutrientsCollected / FOOD_PER_GROWTH_LEVEL);
    }

    private float playerGrowthScale() {
        return 1f + growthLevel() * 0.15f;
    }

    private float cameraZoom() {
        return 1f / (1f + growthLevel() * 0.2f);
    }

    private int nextRandomInt(int bound) {
        randomState = (randomState * 25_214_903_917L + 11L) & ((1L << 48) - 1);
        return (int) (randomState % bound);
    }

    private float nextRandomFloat() {
        return nextRandomInt(1 << 24) / (float) (1 << 24);
    }

    private boolean nextRandomBoolean() {
        return nextRandomInt(2) == 0;
    }

    private void handleTouch(float x, float y) {
        if (screen == Screen.SETUP) {
            float cardWidth = Math.min(getWidth() * 0.29f, 160f * density);
            float gap = 14f * density;
            float cardY = getHeight() * 0.36f;
            float cardHeight = 108f * density;
            float totalWidth = cardWidth * 3f + gap * 2f;
            float left = (getWidth() - totalWidth) * 0.5f;
            RectF herbivore = new RectF(left, cardY, left + cardWidth, cardY + cardHeight);
            RectF carnivoreCard = new RectF(left + cardWidth + gap, cardY,
                    left + cardWidth * 2f + gap, cardY + cardHeight);
            RectF omnivoreCard = new RectF(left + cardWidth * 2f + gap * 2f, cardY,
                    left + totalWidth, cardY + cardHeight);
            if (herbivore.contains(x, y)) {
                diet = Diet.HERBIVORE;
            } else if (carnivoreCard.contains(x, y)) {
                diet = Diet.CARNIVORE;
            } else if (omnivoreCard.contains(x, y)) {
                diet = Diet.OMNIVORE;
            } else if (primaryButton.contains(x, y)) {
                startGame();
            } else if (secondaryButton.contains(x, y)) {
                difficulty = (difficulty + 1) % 3;
            }
            saveSession();
            invalidate();
            return;
        }

        if (screen == Screen.GAME && primaryButton.contains(x, y)) {
            screen = Screen.EDITOR;
            saveSession();
            invalidate();
            return;
        }
        if (screen == Screen.GAME) {
            setTargetFromScreen(x, y);
            return;
        }
        if (screen == Screen.EDITOR) {
            if (primaryButton.contains(x, y)) {
                addedParts++;
            } else if (secondaryButton.contains(x, y)) {
                screen = Screen.GAME;
                if (running) {
                    lastFrameNanos = 0L;
                    postOnAnimation(frameClock);
                }
            }
            saveSession();
            invalidate();
            return;
        }

    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                handleTouch(event.getX(), event.getY());
                return true;
            case MotionEvent.ACTION_MOVE:
                if (screen == Screen.GAME) {
                    setTargetFromScreen(event.getX(), event.getY());
                }
                return true;
            case MotionEvent.ACTION_UP:
                performClick();
                return true;
            case MotionEvent.ACTION_CANCEL:
                return true;
            default:
                return false;
        }
    }

    @Override
    public boolean performClick() {
        super.performClick();
        return true;
    }

    private void setTargetFromScreen(float x, float y) {
        float zoom = cameraZoom();
        targetX = playerX + (x - getWidth() * 0.5f) / zoom;
        targetY = playerY + (y - getHeight() * 0.5f) / zoom;
        hasPosition = true;
    }

    private static float distanceSquared(float firstX, float firstY, float secondX, float secondY) {
        float dx = firstX - secondX;
        float dy = firstY - secondY;
        return dx * dx + dy * dy;
    }

    private void saveSession() {
        int width = getWidth();
        int height = getHeight();
        if (width <= 0 || height <= 0) {
            return;
        }

        StringBuilder savedFood = new StringBuilder();
        for (Food item : food) {
            if (savedFood.length() > 0) {
                savedFood.append(';');
            }
            savedFood.append(item.x).append(',')
                    .append(item.y).append(',')
                    .append(item.radius / density).append(',')
                    .append(item.kind.name());
        }

        SharedPreferences.Editor editor = getContext()
                .getSharedPreferences(SAVE_PREFERENCES, Context.MODE_PRIVATE).edit();
        editor.putInt("version", SAVE_VERSION)
                .putString("screen", screen.name())
                .putString("diet", diet.name())
                .putInt("difficulty", difficulty)
                .putInt("nutrients", nutrientsCollected)
                .putInt("parts", partsCollected)
                .putInt("added_parts", addedParts)
                .putBoolean("has_position", hasPosition)
                .putFloat("player_x", playerX)
                .putFloat("player_y", playerY)
                .putFloat("target_x", targetX)
                .putFloat("target_y", targetY)
                .putFloat("velocity_x", velocityX)
                .putFloat("velocity_y", velocityY)
                .putLong("random_state", randomState)
                .putString("food", savedFood.toString())
                .apply();
    }

    private void restoreSession() {
        SavedSession saved = pendingRestore;
        pendingRestore = null;
        screen = saved.screen;
        diet = saved.diet;
        difficulty = saved.difficulty;
        nutrientsCollected = saved.nutrientsCollected;
        partsCollected = saved.partsCollected;
        addedParts = saved.addedParts;
        hasPosition = saved.hasPosition;
        playerX = saved.playerX;
        playerY = saved.playerY;
        targetX = saved.targetX;
        targetY = saved.targetY;
        velocityX = saved.velocityX;
        velocityY = saved.velocityY;
        randomState = saved.randomState;
        food.clear();
        for (SavedFood item : saved.food) {
            food.add(new Food(item.x, item.y,
                    item.radiusDp * density, item.kind));
        }
        invalidate();
        if (running && screen == Screen.GAME) {
            lastFrameNanos = 0L;
            postOnAnimation(frameClock);
        }
    }

    private static SavedSession loadSession(SharedPreferences preferences) {
        if (!preferences.contains("version")) {
            return null;
        }
        int savedVersion = preferences.getInt("version", -1);
        if (savedVersion != SAVE_VERSION) {
            Log.w(TAG, "Ignoring saved session with an unsupported version.");
            if (savedVersion < SAVE_VERSION) {
                preferences.edit().clear().apply();
            }
            return null;
        }

        try {
            SavedSession saved = new SavedSession();
            String savedScreen = preferences.getString("screen", null);
            if (savedScreen == null) {
                throw new IllegalArgumentException("Saved session has no screen.");
            }
            saved.screen = Screen.valueOf(savedScreen);
            String savedDiet = preferences.getString("diet", null);
            if (savedDiet == null) {
                throw new IllegalArgumentException("Saved session has no diet.");
            }
            saved.diet = Diet.valueOf(savedDiet);
            saved.difficulty = preferences.getInt("difficulty", -1);
            saved.nutrientsCollected = preferences.getInt("nutrients", -1);
            saved.partsCollected = preferences.getInt("parts", -1);
            saved.addedParts = preferences.getInt("added_parts", -1);
            saved.hasPosition = preferences.getBoolean("has_position", false);
            saved.playerX = preferences.getFloat("player_x", Float.NaN);
            saved.playerY = preferences.getFloat("player_y", Float.NaN);
            saved.targetX = preferences.getFloat("target_x", Float.NaN);
            saved.targetY = preferences.getFloat("target_y", Float.NaN);
            saved.velocityX = preferences.getFloat("velocity_x", Float.NaN);
            saved.velocityY = preferences.getFloat("velocity_y", Float.NaN);
            saved.randomState = preferences.getLong("random_state", -1L);
            if (saved.difficulty < 0 || saved.difficulty > 2 ||
                    saved.nutrientsCollected < 0 || saved.partsCollected < 0 ||
                    saved.addedParts < 0 ||
                    !isValidWorldCoordinate(saved.playerX) ||
                    !isValidWorldCoordinate(saved.playerY) ||
                    !isValidWorldCoordinate(saved.targetX) ||
                    !isValidWorldCoordinate(saved.targetY) ||
                    !isValidVelocity(saved.velocityX) || !isValidVelocity(saved.velocityY) ||
                    saved.randomState < 0 || saved.randomState >= (1L << 48)) {
                throw new IllegalArgumentException("Saved session values are out of range.");
            }

            String savedFood = preferences.getString("food", "");
            if (savedFood == null) {
                throw new IllegalArgumentException("Saved session has no food data.");
            }
            if (!savedFood.isEmpty()) {
                String[] entries = savedFood.split(";", -1);
                if (entries.length > FOOD_COUNT) {
                    throw new IllegalArgumentException("Saved session has too many food items.");
                }
                for (String entry : entries) {
                    String[] values = entry.split(",", -1);
                    if (values.length != 4) {
                        throw new IllegalArgumentException("Saved food entry is malformed.");
                    }
                    float x = Float.parseFloat(values[0]);
                    float y = Float.parseFloat(values[1]);
                    float radiusDp = Float.parseFloat(values[2]);
                    FoodKind kind = FoodKind.valueOf(values[3]);
                    if (!isValidWorldCoordinate(x) || !isValidWorldCoordinate(y) ||
                            !Float.isFinite(radiusDp) || radiusDp <= 0f || radiusDp > 100f) {
                        throw new IllegalArgumentException("Saved food values are out of range.");
                    }
                    saved.food.add(new SavedFood(x, y, radiusDp, kind));
                }
            }
            return saved;
        } catch (IllegalArgumentException exception) {
            Log.w(TAG, "Discarding invalid saved session.", exception);
            preferences.edit().clear().apply();
            return null;
        }
    }

    private static boolean isValidWorldCoordinate(float value) {
        return Float.isFinite(value) && Math.abs(value) <= 10_000_000f;
    }

    private static boolean isValidVelocity(float value) {
        return Float.isFinite(value) && Math.abs(value) <= 5_000f;
    }

    private final class HandlerFrameClock implements Runnable {
        @Override
        public void run() {
            if (!running || screen != Screen.GAME) {
                return;
            }
            long now = System.nanoTime();
            float deltaSeconds = lastFrameNanos == 0L ? 0f :
                    Math.min((now - lastFrameNanos) / 1_000_000_000f, 0.05f);
            lastFrameNanos = now;
            lastFrameSeconds += deltaSeconds;
            if (lastFrameSeconds >= 0.05f) {
                updateGame(lastFrameSeconds);
                lastFrameSeconds = 0f;
            }
            postInvalidateOnAnimation();
            postOnAnimation(this);
        }
    }

    private static final class Food {
        final float x;
        final float y;
        final float radius;
        final FoodKind kind;

        Food(float x, float y, float radius, FoodKind kind) {
            this.x = x;
            this.y = y;
            this.radius = radius;
            this.kind = kind;
        }
    }

    private static final class SavedSession {
        Screen screen;
        Diet diet;
        int difficulty;
        int nutrientsCollected;
        int partsCollected;
        int addedParts;
        boolean hasPosition;
        float playerX;
        float playerY;
        float targetX;
        float targetY;
        float velocityX;
        float velocityY;
        long randomState;
        final List<SavedFood> food = new ArrayList<>();
    }

    private static final class SavedFood {
        final float x;
        final float y;
        final float radiusDp;
        final FoodKind kind;

        SavedFood(float x, float y, float radiusDp, FoodKind kind) {
            this.x = x;
            this.y = y;
            this.radiusDp = radiusDp;
            this.kind = kind;
        }
    }
}
