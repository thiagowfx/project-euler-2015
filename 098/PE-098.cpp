/*
 * What is the largest square number formed by any member of such a pair?
 */
#include <bits/stdc++.h>

std::vector<long long int> squares;
inline void populate_squares(long long int limit = 31700) {
    for(long long int i = 2; i < limit; ++i) {
        squares.push_back(i * i);
    }
}

long long int square_anagram(const std::string& s1, const std::string& s2) {
    long long int greatest = (-1);

    for(unsigned i = 0; i < squares.size(); ++i) {
        unsigned square_length = std::to_string(squares[i]).size();

        // too short, keep going
        if(square_length < s1.size())
            continue;

        // too big, stop now
        if(square_length > s1.size())
            break;

        bool match = true;
        long long int square = squares[i];

        std::map<char, int> m;

        // create a map from the first word
        for(int j = static_cast<int>(s1.size()) - 1; j >= 0; --j) {
            long long int digit = square % 10;
            square /= 10;

            // repeated letter is found, but it doesn't match the square pattern
            if (m.find(s1[j]) != m.end()) {
                if (m[s1[j]] == digit) {
                    continue;
                }
                else {
                    match = false;
                    break;
                }
            }

            // value already used
            bool doBreak = false;
            for(std::map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
                if(it->second == digit) {
                    match = false;
                    doBreak = true;
                    break;
                }
            }
            if(doBreak)
                break;

            m[s1[j]] = digit;
        }

        if (!match) {
            continue;
        }

        // second word
        long long int value = 0;

        if (m[s2[0]] == 0) {
            match = false;
        }
        else {
            for(unsigned j = 0; j < s2.size(); ++j) {
                value = 10 * value + m[s2[j]];
            }
        }

        if (!match) {
            continue;
        }

        if (std::binary_search(squares.begin(), squares.end(), value)) {
            long long int max_pair = std::max(value, squares[i]);
            greatest = std::max(greatest, max_pair);
        }
    }

    return greatest;
}

long long int solve(std::ifstream& ifs) {
    long long int ans = 0;

    std::vector<std::string> words;
    std::vector<std::string> words_sorted;

    // populate words
    std::string word;
    while (std::getline(ifs, word, ',')) {
        words.push_back(std::string(word.begin() + 1, word.end() - 1));
    }

    // sort individual words
    words_sorted = words;
    for(unsigned i = 0; i < words.size(); ++i) {
        std::sort(words_sorted[i].begin(), words_sorted[i].end());
        // std::cout << words[i] << " " << words_sorted[i] << std::endl;
    }

    for(unsigned i = 0; i < words.size(); ++i) {
        for(unsigned j = i + 1; j < words.size(); ++j) {
            if(words_sorted[i].size() != words_sorted[j].size())
                continue;

            bool equal = true;
            for(unsigned k = 0; k < words_sorted[i].size(); ++k) {
                equal = (words_sorted[i][k] == words_sorted[j][k]);
                if(!equal)
                    break;
            }

            if(equal) {
                long long int pair_value = square_anagram(words[i], words[j]);
                if(pair_value > ans) {
                    ans = pair_value;
                }
                // std::cout << words[i] << " and " << words[j] << " --> " << pair_value << std::endl;
            }
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {
    std::ifstream ifs(argv[1]);
    populate_squares();

    assert(square_anagram("CARE", "RACE") == 9216);

    std::cout << solve(ifs) << std::endl;
    return 0;
}
