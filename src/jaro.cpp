#include <string>
#include <cmath>

float jaro(std::string* src, std::string* dest)
{
    int len_src = src->length();
    int len_dest = dest->length();
    float sim = 0;

    if (*src == *dest){
        sim = 1.0;
    }

    int window = std::floor(std::max(len_src, len_dest)/2) -1;

    int matches = 0;

    int match_mask_src[len_src] = {0};
    int match_mask_dest[len_dest] = {0};

    for (int i=0; i<len_src; i++)
    {
        for (int j=std::max(0, i-window); j < std::min(len_dest, i+window+1); j++)
        {
            if (src->at(i)==dest->at(j) && match_mask_dest[j]==0)
            {
                match_mask_src[i] = 1;
                match_mask_dest[j] = 1;
                matches += 1;
                break;
            }
        }
    }

    if (matches==0)
        sim = 0.0;

    float transpos = 0;
    int k = 0;

    for (int i=0;i<len_src;i++)
    {
        if (match_mask_src[i]) {
            while (match_mask_dest[k]==0)
                k++;
            if (src->at(i)!=dest->at(k++))
                transpos++;
        }
    }

    transpos/=2;

    sim = ( ((double)matches) / ((double)len_src)
            +((double)matches) / ((double)len_dest)
            +((double)matches - transpos) / ((double)matches)
        ) / 3.0;

    return sim;

}



float jaro_winkler(std::string* src, std::string* dest)
{
    float jaro_sim = jaro(src, dest);
    int len_src = src->length();
    int len_dest = dest->length();   
    int prefix_limit = std::min(4, std::min(len_src, len_dest));
    int common_prefix = 0;

    for (int i=0; i < prefix_limit; i++)
    {
        if (src->at(i)==dest->at(i))
        {
            common_prefix += 1;
        }
    }

    jaro_sim += 0.1 * common_prefix * (1-jaro_sim);
    return jaro_sim;
}