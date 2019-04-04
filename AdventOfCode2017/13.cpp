#include<bits/stdc++.h>
int main()
{
    std::ifstream in ("input13.txt");
    std::vector<std::pair<int, int>> scanners;
    std::string _;
    int depth, range;
    while (in >> depth >> _ >> range)
        scanners.emplace_back(depth, range);

    int delay = 0;
    while (!std::all_of(scanners.begin(), scanners.end(), [=](auto& p){ return (delay + p.first) % (2 * p.second - 2) != 0; }))
        ++delay;

    std::cout << delay << std::endl;
    return 0;
}
