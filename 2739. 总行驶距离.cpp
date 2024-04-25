//2739. 总行驶距离
//卡车有两个油箱。给你两个整数，mainTank 表示主油箱中的燃料（以升为单位），additionalTank 表示副油箱中的燃料（以升为单位）。
//该卡车每耗费 1 升燃料都可以行驶 10 km。每当主油箱使用了 5 升燃料时，如果副油箱至少有 1 升燃料，则会将 1 升燃料从副油箱转移到主油箱。
//返回卡车可以行驶的最大距离。
//注意：从副油箱向主油箱注入燃料不是连续行为。这一事件会在每消耗 5 升燃料时突然且立即发生。

//示例 1：
//输入：mainTank = 5, additionalTank = 10
//输出：60
//解释：
//在用掉 5 升燃料后，主油箱中燃料还剩下 (5 - 5 + 1) = 1 升，行驶距离为 50km 。
//在用掉剩下的 1 升燃料后，没有新的燃料注入到主油箱中，主油箱变为空。
//总行驶距离为 60km 。

//示例 2：
//输入：mainTank = 1, additionalTank = 2
//输出：10
//解释：
//在用掉 1 升燃料后，主油箱变为空。
//总行驶距离为 10km 。

#include <iostream>

class Solution {
public:
    /**
     * 计算卡车可以行驶的最大距离
     * @param mainTank 主油箱中的燃料（以升为单位）
     * @param additionalTank 副油箱中的燃料（以升为单位）
     * @return 卡车可以行驶的最大距离（以千米为单位）
     */
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            ans += 50; // 每消耗 5 升燃料行驶 50 km
            if (additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        return ans + mainTank * 10; // 加上主油箱剩余燃料可行驶的距离
    }
};

int main() {
    Solution solution;
    int mainTank = 5; // 主油箱中的燃料
    int additionalTank = 10; // 副油箱中的燃料
    int maxDistance = solution.distanceTraveled(mainTank, additionalTank);
    std::cout << "卡车可以行驶的最大距离为：" << maxDistance << " km" << std::endl;

    return 0;
}
