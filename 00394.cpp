#include<iostream>
#include<map>
using namespace std;
//Using long longs just to be safe
typedef long long ll;

struct array
{
    string name;
    ll base;
    ll byte;
    ll dim;
    ll upper[11];
    ll lower[11];
    ll constant[11];
};

int main()
{
    ll n,r;
    ll indexes[11];
    map<string, ll> order;

    cin >> n >> r;
    array* arrays = new array[n];
    

    //Build each array
    for(ll i = 0; i < n; i++)
    {
	//Get name, base address, byte size, and number of dimensions
	cin >> arrays[i].name >> arrays[i].base >> arrays[i].byte >> arrays[i].dim;
	//Keep track of the order the arrays came in
	order[arrays[i].name] = i;
	arrays[i].constant[ arrays[i].dim ] = arrays[i].byte;

	//Get the upper and lower bounds
	for(ll j = 1; j <= arrays[i].dim; j++)
	    cin >> arrays[i].lower[j] >> arrays[i].upper[j];

	//Build the constant array starting fromt the highest dimension
	for(ll j = arrays[i].dim -1; j >= 1; j--)
	{
	    arrays[i].constant[j] = arrays[i].constant[j+1] * (arrays[i].upper[j+1] - arrays[i].lower[j+1] + 1);
	}
    }
    for(ll i = 0; i < r; i++)
    {
	string name;
	ll address = 0;
	cin >> name;
	cout << name << '[';
	ll arrNum = order[name];

	//Get the indexes
	for(ll j = 1; j <= arrays[arrNum].dim; j++)
	{
	    cin >> indexes[j];
	    if(j != 1)
		cout << ", ";
	    cout << indexes[j];
	}
	cout << "] = ";

	//Calculaate the address
	address += arrays[arrNum].base;
	for(ll i = 1; i <= arrays[arrNum].dim; i++)
	    address += arrays[arrNum].constant[i]*(indexes[i]- arrays[arrNum].lower[i]);


	cout << address << endl;
    }
    delete[] arrays;
    return 0;
}
