#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// Driver program to test above functions
int main()
{
    int n, k;
    cin >> n >> k;
	ordered_set o_set;

	for(int i=1;i<=n;i++){
        o_set.insert(i);
    }

    int pos = k%n;

    while(!o_set.empty()){
        int val = *o_set.find_by_order(pos);
        o_set.erase(val);
        cout << val << " ";

        if(!o_set.empty()){
            pos = (pos+k)%o_set.size();
        }
    }

	return 0;
}
