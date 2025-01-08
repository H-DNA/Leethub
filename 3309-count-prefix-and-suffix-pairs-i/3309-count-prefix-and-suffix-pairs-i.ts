function countPrefixSuffixPairs(words: string[]): number {
    let res = 0;
    for (let i = 0; i < words.length; ++i) {
        for (let j = i + 1; j < words.length; ++j) {
            if (words[j].startsWith(words[i]) && words[j].endsWith(words[i])) res += 1;
        }
    }
    return res;
};