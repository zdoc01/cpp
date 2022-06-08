#include <iostream>
#include <map>
#include <string>
#include <vector>

/*
 * Complete the 'sockMerchant' function below. Must return an integer
 * representing the number of matching pairs of socks that are available.
 *
 * For example, there are `n = 7` socks with colors `ar = [1,2,1,2,1,3,2]`.
 * There is one pair of color 1 and one of color 2. There are three odd socks
 * left, one of each color. The number of pairs is `2`.
 *
 * @param n Number of socks
 * @param ar Color values for each sock
 * @return Number of matching pairs
 */
int sockMerchant(int n, std::vector<int> ar)
{
    std::map<int, int> color_count_map;

    // Count the number of socks per color value
    for (auto color_val : ar)
    {
        if (!color_count_map[color_val])
        {
            color_count_map[color_val] = 0;
        }
        color_count_map[color_val]++;
    }

    int num_pairs = 0;
    for (const auto [k, v] : color_count_map)
    {
        // If there are 2 or more of a given color value, we know we have
        // at least one pair
        if (v >= 2)
        {
            // Calculate the number of pairs for this color value, and
            // add it to our total
            num_pairs += (v - v % 2) / 2;
        }
    }

    return num_pairs;
}

int main()
{
    std::vector<int> const sockColorValues = {1, 2, 1, 2, 1, 3, 2};
    std::cout << "Number of pairs = " << sockMerchant(sockColorValues.size(), sockColorValues) << std::endl;
    return 0;
}