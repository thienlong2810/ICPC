using namespace std;
using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randInt(ll L , ll R){
    return L + 1ULL * rng() % (R - L + 1);
}
