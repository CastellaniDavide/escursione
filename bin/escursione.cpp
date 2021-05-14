/**
 * @file party.cpp
 *
 * @version 01.01 2021514
 *
 * @brief
 *
 * @ingroup party
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

// Variabiles
int T, N, M;
vector < vector <int> > mymap;
vector < vector <int> > mysol;
queue < pair <int, int> > q;

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    freopen("escursione_input_1.txt", "r", stdin);
    freopen("escursione_output_1.txt", "w", stdout);

    // Input
    cin >> T;

    for (size_t t = 0; t < T; ++t)
    {
        cin >> N >> M;
        mymap.empty();
        mysol.empty();
        mymap.resize(N);
        mysol.resize(N);
        for (size_t i = 0; i < N; ++i)
        {
            mymap[i].resize(M);
            mysol[i].resize(M);
        }

        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                cin >> mymap[i][j];
                mysol[i][j] = INT_MAX;
            }
        }

        q.push(make_pair(0, 0));
        mysol[0][0] = 0;

        while (!q.empty())
        {
            pair <int, int> pos = q.front();
            q.pop();

            if (pos.first < N - 1 && mysol[pos.first + 1][pos.second] > max(
                        mysol[pos.first][pos.second],
                        abs(
                            mymap[pos.first][pos.second] -
                            mymap[pos.first + 1][pos.second]
                        )
                    )
               )
            {

                mysol[pos.first + 1][pos.second] = max(
                                                       mysol[pos.first][pos.second],
                                                       abs(
                                                               mymap[pos.first][pos.second] -
                                                               mymap[pos.first + 1][pos.second]
                                                       )
                                                   );
                q.push(make_pair(pos.first + 1, pos.second));
            }

            if (pos.second < M  - 1&&
                    mysol[pos.first][pos.second + 1] > max(
                        mysol[pos.first][pos.second],
                        abs(
                            mymap[pos.first][pos.second] -
                            mymap[pos.first][pos.second + 1]
                        )
                    )
               )
            {
                mysol[pos.first][pos.second + 1] = max(
                                                       mysol[pos.first][pos.second],
                                                       abs(
                                                               mymap[pos.first][pos.second] -
                                                               mymap[pos.first][pos.second + 1]
                                                       )
                                                   );
                q.push(make_pair(pos.first, pos.second + 1));
            }

            if (pos.first > 0 &&
                mysol[pos.first - 1][pos.second] > max(
                        mysol[pos.first][pos.second],
                        abs(
                            mymap[pos.first][pos.second] -
                            mymap[pos.first - 1][pos.second]
                        )
                    )
               )
            {

                mysol[pos.first - 1][pos.second] = max(
                                                       mysol[pos.first][pos.second],
                                                       abs(
                                                               mymap[pos.first][pos.second] -
                                                               mymap[pos.first - 1][pos.second]
                                                       )
                                                   );
                q.push(make_pair(pos.first - 1, pos.second));
            }

            if (pos.second > 0 &&
                    mysol[pos.first][pos.second - 1] > max(
                        mysol[pos.first][pos.second],
                        abs(
                            mymap[pos.first][pos.second] -
                            mymap[pos.first][pos.second - 1]
                        )
                    )
               )
            {
                mysol[pos.first][pos.second - 1] = max(
                                                       mysol[pos.first][pos.second],
                                                       abs(
                                                               mymap[pos.first][pos.second] -
                                                               mymap[pos.first][pos.second - 1]
                                                       )
                                                   );
                q.push(make_pair(pos.first, pos.second - 1));
            }
        }

#ifdef DEBUG
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                cout << mysol[i][j] << "\t";
            }
            cout << endl;
        }
#endif // DEBUG

        cout << "Case #" << t + 1 << ": " << mysol[N - 1][M - 1] << endl;
    }

    // End
    return 0;
}
