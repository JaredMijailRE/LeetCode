class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        answer = []
        for index, word in enumerate(words):
            for index2 in range(index+1, len(words)):
                if(len(word)>len(words[index2])):
                    small, big = words[index2], word
                else:
                    big, small = words[index2], word
                if small in big and small not in answer:
                    answer.append(small)
        return answer

        