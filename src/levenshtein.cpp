#include <string>
#include <iostream>


int levenshtein(const std::string* src, const std::string* dest)
{
    int len_src = src->length();
    int len_dest = dest->length();
    int lev_dist = 0;

    if (len_src == 0 && len_dest == 0)
    {
        lev_dist = 0;
    }
    else if (len_src == 0)
    {
        lev_dist = len_dest;
    }
    else if (len_dest ==0)
    {
        lev_dist = len_src;
    }
    else
    {
        int LevMat[len_src+1][len_dest+1];

        for (int i=0; i<= len_src; i++)
        {
            for (int j=0; j<= len_dest; j++)
            {
                if (i==0 || j==0)
                {
                    LevMat[i][j] = std::max(i,j);
                }

                else {
                    int fromLeftCell = LevMat[i-1][j] + 1;
                    int fromUpperCell = LevMat[i][j-1] + 1;
                    int fromDiagCell = LevMat[i-1][j-1];
                    if (src->at(i-1)!=dest->at(j-1))
                    {
                        fromDiagCell += 1;
                    }
                    LevMat[i][j] = std::min(fromLeftCell, std::min(fromUpperCell, fromDiagCell));
                }
            }
        }

        lev_dist = LevMat[len_src][len_dest];
    }
    return lev_dist;
}