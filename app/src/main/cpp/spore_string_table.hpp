#pragma once

#include <cstddef>
#include <cstdint>

namespace spore::string_table {

struct Record {
    std::uint32_t key;
    std::uint32_t value_address;
    std::uint32_t reserved;
};

static_assert(sizeof(Record) == 12);

inline void adjustHeap(
    Record* records,
    std::size_t first,
    std::size_t count,
    std::size_t hole,
    Record value) {
    std::size_t right_child;
    for (;;) {
        right_child = hole * 2 + 2;
        if (count <= right_child) {
            break;
        }
        std::size_t child = right_child;
        if (records[child].key < records[child - 1].key) {
            --child;
        }
        records[hole] = records[child];
        hole = child;
    }

    if (right_child == count) {
        records[hole] = records[right_child - 1];
        hole = right_child - 1;
    }

    while (first < hole) {
        const std::size_t parent = (hole - 1) / 2;
        if (!(records[parent].key < value.key)) {
            break;
        }
        records[hole] = records[parent];
        hole = parent;
    }
    records[hole] = value;
}

inline void makeHeap(Record* begin, std::size_t count) {
    if (count < 2) {
        return;
    }

    std::size_t parent = (count - 2) / 2 + 1;
    while (parent != 0) {
        --parent;
        adjustHeap(begin, parent, count, parent, begin[parent]);
    }
}

inline void heapSort(Record* begin, Record* end) {
    const std::size_t count = static_cast<std::size_t>(end - begin);
    makeHeap(begin, count);
    for (std::size_t heap_size = count; heap_size > 1; --heap_size) {
        const Record value = begin[heap_size - 1];
        begin[heap_size - 1] = begin[0];
        adjustHeap(begin, 0, heap_size - 1, 0, value);
    }
}

inline void quickSort(Record* begin, Record* end, std::int32_t depth) {
    std::ptrdiff_t count = end - begin;
    while (count > 28 && depth > 0) {
        Record* const last = end - 1;
        Record* middle = begin + count / 2;
        if (begin->key < middle->key) {
            if (last->key <= middle->key) {
                middle = last;
                if (last->key <= begin->key) {
                    middle = begin;
                }
            }
        } else if (begin->key < last->key) {
            middle = begin;
        } else if (middle->key < last->key) {
            middle = last;
        }

        const std::uint32_t pivot = middle->key;
        Record* left = begin;
        Record* right = end;
        for (;;) {
            while (left->key < pivot) {
                ++left;
            }
            do {
                --right;
            } while (pivot < right->key);
            if (right <= left) {
                break;
            }
            const Record value = *left;
            *left = *right;
            *right = value;
            ++left;
        }

        --depth;
        quickSort(left, end, depth);
        end = left;
        count = end - begin;
    }

    if (depth == 0) {
        heapSort(begin, end);
    }
}

inline void insertionSort(Record* begin, Record* end) {
    for (Record* current = begin + (begin != end); current != end; ++current) {
        const Record value = *current;
        Record* hole = current;
        while (hole != begin && value.key < (hole - 1)->key) {
            *hole = *(hole - 1);
            --hole;
        }
        *hole = value;
    }
}

inline void sort(Record* begin, Record* end) {
    if (begin == end) {
        return;
    }

    const std::size_t count = static_cast<std::size_t>(end - begin);
    std::size_t remaining = count;
    std::int32_t log2_count = 0;
    while (remaining != 0) {
        ++log2_count;
        remaining >>= 1;
    }

    quickSort(begin, end, log2_count * 2 - 2);
    if (count < 29) {
        insertionSort(begin, end);
        return;
    }

    Record* const prefix_end = begin + 28;
    insertionSort(begin, prefix_end);
    for (Record* current = prefix_end; current != end; ++current) {
        const Record value = *current;
        Record* hole = current;
        while (hole != begin && value.key < (hole - 1)->key) {
            *hole = *(hole - 1);
            --hole;
        }
        *hole = value;
    }
}

inline Record* lowerBound(Record* begin, Record* end, const std::uint32_t* key) {
    std::int32_t count = static_cast<std::int32_t>(end - begin);
    while (count > 0) {
        const std::int32_t half = count >> 1;
        Record* middle = begin + half;
        if (middle->key < *key) {
            begin = middle + 1;
            count -= half + 1;
        } else {
            count = half;
        }
    }
    return begin;
}

}  // namespace spore::string_table
