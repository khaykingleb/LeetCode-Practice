#include <iostream>
#include <vector>
#include <limits>

void merge(std::vector<int>& A, const int left, const int middle, const int right)
{
    const int n_1 = middle - left + 1;
    const int n_2 = right - middle;

    std::vector<int> L(n_1 + 1), R(n_2 + 1);

    for(int i = 0; i < n_1; i++)
        L[i] = A[left + i];

    for(int j = 0; j < n_2; j++)
        R[j] = A[middle + j + 1];

    L[n_1] = std::numeric_limits<int>::max();
    R[n_2] = std::numeric_limits<int>::max();

    int i = 0;
    int j = 0;

    for(int k = left; k <= right; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        } else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(std::vector<int>& A, const int left, const int right)
{
    if(left < right)
    {
        int middle = (left + right) / 2;
        merge_sort(A, left, middle);
        merge_sort(A, middle + 1, right);
        merge(A, left, middle, right);
    }
}

std::vector<int> sort_array(std::vector<int>& nums) 
{
    merge_sort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    int n {};
    std::cin >> n;

    std::vector<int> v(n);
    for(auto& i : v)
        std::cin >> i;

    v_new = sort_array(v);
    for(const auto& i : v_new)
        std::cout << i << " ";

    return 0;
}
