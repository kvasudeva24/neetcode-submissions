class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        word_counter = {}
        for word in strs:
            count = [0] * 26

            for char in word:
                index = ord(char) - ord('a')
                count[index] += 1

            key = tuple(count)
            if key not in word_counter:
                word_counter[key] = [word]
            else:
                word_counter[key].append(word)
            

        return list(word_counter.values())
            

        