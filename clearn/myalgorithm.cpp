#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

namespace cplusBinarySearch
{
    //���ַ��Ĺؼ�˼����ǹ�ע���������䡰�ı仯

    /// <summary>
    /// ��򵥱�׼�Ķ��ֲ���
    /// </summary>
    /// <param name="nums">Ҫ���ҵ����飨vector��</param>
    /// <param name="target">Ҫ���ҵ�Ŀ��</param>
    /// <returns></returns>
    template<class T>
    int binarySearch(vector<T> nums, T target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {//��Ϊ�Ǳ�����������<=
            int mid = left + (right - left) / 2; //�������������int
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;
    }
    /// <summary>
    /// ���ַ����ң�������ͬԪ���е������һ��
    /// </summary>
    /// <param name="nums"></param>
    /// <param name="target"></param>
    /// <returns></returns>
    template<class T>
    int left_bound(vector<T> nums, T target) {
        int left = 0, right = nums.size() - 1;
        // ��������Ϊ [left, right]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                // ���������Ϊ [mid+1, right]
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                // ���������Ϊ [left, mid-1]
                right = mid - 1;
            }
            else if (nums[mid] == target) {
                // �����Ҳ�߽�
                right = mid - 1;
            }
        }
        // ���������
        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }
}

namespace cBinarySearch
{
    int binary_search(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] == target) {
                // ֱ�ӷ���
                return mid;
            }
        }
        // ֱ�ӷ���
        return -1;
    }

    int left_bound(vector<int>  nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] == target) {
                // �𷵻أ��������߽�
                right = mid - 1;
            }
        }
        // ���Ҫ��� left Խ������
        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    int right_bound(vector<int>  nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] == target) {
                // �𷵻أ������Ҳ�߽�
                left = mid + 1;
            }
        }
        // ���Ҫ��� right Խ������
        if (right < 0 || nums[right] != target)
            return -1;
        return right;
    }
}