#include <string>
#include <cmath>


// LCS Similarity defined as len(common_substring)/(sqrt(len(src)) * sqrt(len(dest)))

std::string lcs(const std::string* src, const std::string* dest)
{
    int len_src = src->length();
    int len_dest = dest->length();
    std::string lcs = "";
    int lcs_len = 0;
    int src_end = 0;

    if (len_src > 0 and len_dest > 0)
    {
        int LCSMat[len_src+1][len_dest+1];

        for (int i=0; i<= len_src; i++)
        {
            for (int j=0; j<= len_dest; j++)
            {
                if (i==0 || j==0)
                {
                    LCSMat[i][j] = 0;
                }

                else if ( src->at(i-1) == dest->at(j-1))
                {
                    LCSMat[i][j] = LCSMat[i-1][j-1] + 1;
                    if (lcs_len <= LCSMat[i][j])
                    {
                        lcs_len = LCSMat[i][j];
                        src_end = i;
                    }
                }

                else 
                {
                    LCSMat[i][j] = 0;
                }
            }
        }

        if (lcs_len > 0)
        {
            lcs = src->substr(src_end - lcs_len, lcs_len);
        }
    }

    return lcs;
}

int lcs_len(const std::string* src, const std::string* dest)
{
    int len = lcs(src, dest).length();
    return len;
}

float lcs_score(const std::string* src, const std::string* dest)
{
    int len_cs = lcs(src, dest).length();
    int len_src = src->length();
    int len_dest = dest->length();

    float score = 0;

    if (len_src > 0 || len_dest > 0)
    {
        score = len_cs/(std::sqrt(len_src) * std::sqrt(len_dest));
    }

    return score;
}