#include <bits/stdc++.h>
using namespace std;

//function to extract integer from input
void extractInteger(vector<int> &data)
{
    string input_str;
    getline(cin, input_str);

    stringstream ss(input_str);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        data.push_back(stoi(substr));
    }
}

int main(int argc, char const *argv[])
{
    freopen("ET_small.txt", "r", stdin);
    freopen("output_ET_small.txt", "w", stdout);

    int township_count;
    string temp_str;

    getline(cin, temp_str);
    township_count = stoi(temp_str);

    //Do for every township
    for (int i = 0; i < township_count; i++)
    {
        int house_count, total_walls = 0;
        double total_hours, accent_walls_qty, regular_walls_qty;

        getline(cin, temp_str);
        house_count = stoi(temp_str);
        
        //Calculate for every house in township
        while(house_count--)
        {
            vector<int> wall_data;

            extractInteger(wall_data);
             // Count total walls
            total_walls += (wall_data[1] * 3 + wall_data[2] * 4 + wall_data[3] * 6);
        }

        total_hours = (double)total_walls * 3;
        accent_walls_qty = (double)total_walls * 0.5;
        regular_walls_qty = (double)total_walls * 1.5;

        printf("Case #%d: %.2lf, %.2lf, %.2lf\n", i + 1, total_hours, accent_walls_qty, regular_walls_qty);
    }
    return 0;
}
