//
// Created by bohua on 2020/6/7.
//

#ifndef ALGORITHM_INDEXMAXHEAP_H
#define ALGORITHM_INDEXMAXHEAP_H

#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

template<typename Item>
class IndexMaxHeap {

private:
    Item *data;

    int *indexes{};
    int count;
    int capacity{};

    void shiftUp(int k) {

        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
            swap(indexes[k / 2], indexes[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {

        // 完全二叉树中，只要有左子节点，他就有子节点
        while (2 * k <= count) {

            int j = 2 * k;  // data[k] 和 data[j] 交换位置
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]]) {
                j++;
            }
            if (data[indexes[k]] >= data[indexes[j]]) {
                break;
            }
            swap(indexes[k], indexes[j]);
            k = j;
        }
    }

public:
    explicit IndexMaxHeap(int capacity) {
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    // 传入的 i 对用户而言，是从0开始索引的
    void insert(int i, Item item) {

        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);

        i++;
        data[i] = item;
        indexes[count + 1] = i;
        count++;
        shiftUp(count);
    }

    Item extractMax() {

        assert(count > 0);

        Item ret = data[indexes[1]];

        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);

        return ret;
    }

    int extractMaxIndex() {

        assert(count > 0);

        int ret = indexes[1] - 1;

        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);

        return ret;
    }

    Item getItem(int i) {
        return data[i + 1];
    }

    void change(int i, Item newItem) {

        i += 1;
        data[i] = newItem;

        // 找到 indexes[j] = i, j 表示 data[i] 在堆中的位置
        // 之后 shiftUp(j), 在 shiftDown(j)
        for (int j = 1; j <= count; ++j) {
            if (indexes[j] == i) {
                shiftUp(j);
                shiftDown(j);
                return;
            }
        }
    }

public:
    // 以树状打印整个堆结构
    void testPrint() {

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if (size() >= 100) {
            cout << "This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if (typeid(Item) != typeid(int)) {
            cout << "This print function can only work for int item";
            return;
        }

        cout << "The max heap size is: " << size() << endl;
        cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(data[i] >= 0 && data[i] < 100);
            cout << data[i] << " ";
        }
        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

#endif //ALGORITHM_INDEXMAXHEAP_H
