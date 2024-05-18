#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int start = 0;

    while (start < words.size())
    {
        int end = start;
        int line_width = words[start].size();

        // Find the end index of the line
        while (end + 1 < words.size() && line_width + words[end + 1].size() + (end + 1 - start) <= maxWidth)
        {
            end++;
            line_width += words[end].size();
        }

        // Construct the line
        string line = words[start];
        int num_words = end - start;
        if (end != start && end != words.size() - 1)
        {
            int spaces = maxWidth - line_width;
            int spaces_per_word = spaces / num_words;
            int extra_spaces = spaces % num_words;

            for (int i = start + 1; i <= end; i++)
            {
                if (i - start <= extra_spaces)
                {
                    line += string(spaces_per_word + 1, ' ');
                }
                else
                {
                    line += string(spaces_per_word, ' ');
                }
                line += words[i];
            }
        }
        else
        {
            // Left-justify the last line
            for (int i = start + 1; i <= end; i++)
            {
                line += " " + words[i];
            }
            line += string(maxWidth - line.size(), ' ');
        }

        // Add the line to the result
        result.push_back(line);

        // Move to the next line
        start = end + 1;
    }

    return result;
}
