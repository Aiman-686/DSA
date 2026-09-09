class Solution:
    def countCommas(self, n: int) -> int:
        answer = 0
        thresold = 1000
        while thresold <= n:
            answer += n - thresold + 1
            thresold *= 1000
        return answer
        