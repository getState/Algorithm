#include <iostream>

#include <string>

#include <algorithm>

#include <cstring> //memset

using namespace std;

const int MAX = 100 + 1;

int N, M;

string cache[MAX][MAX];

string bigNumAdd(string num1, string num2)

{

    long long sum = 0;

    string result;

    //1의 자리부터 더하기 시작한다

    while (!num1.empty() || !num2.empty() || sum)

    {

        if (!num1.empty())

        {

            sum += num1.back() - '0';

            num1.pop_back();
        }

        if (!num2.empty())

        {

            sum += num2.back() - '0';

            num2.pop_back();
        }

        //다시 string 형태로 만들어 push_back

        result.push_back((sum % 10) + '0');

        sum /= 10;
    }

    //1의 자리부터 result에 넣었으므로 뒤집어줘야한다

    reverse(result.begin(), result.end());

    return result;
}

//nCr = n-1Cr + n-1Cr-1

string combination(int n, int r)

{

    if (n == r || r == 0)

        return "1";

    string &result = cache[n][r];

    if (result != "")

        return result;

    result = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));

    return result;
}

int main(void)

{

    cin >> N >> M;

    cout << combination(N, M) << endl;

    return 0;
}
