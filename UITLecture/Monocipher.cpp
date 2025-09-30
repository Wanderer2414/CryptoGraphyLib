#include <string>
#include <iostream>
#include <cstring>
int main() {
    std::string str;
    std::string key = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    std::getline(std::cin, str);
    std::cout << std::endl;
    int arr[26], indices[26];
    for (int i = 0; i<26; i++) indices[i] = i;
    std::memset(arr, 0, sizeof(int)*26);
    for (int i = 0; i<str.size(); i++) {
        if (str[i]>='a' && str[i] <= 'z') {
            arr[str[i]-'a']++;
        }
    }
    for (int i = 1; i<26; i++) {
        int j = i;
        while (j>=1 && arr[indices[j]]>arr[indices[j-1]]) {
            std::swap(indices[j], indices[j-1]);
            j--;
        }
    }
    for (int i = 0; i<26; i++) {
        arr[indices[i]] = key[i];
    }
    for (int i = 0; i<str.size(); i++) {
        if (str[i]>='a' && str[i] <= 'z') {
            str[i] = arr[str[i]-'a'];
        }
    }
    // std::cout << str << std::endl;
    return 0;
}