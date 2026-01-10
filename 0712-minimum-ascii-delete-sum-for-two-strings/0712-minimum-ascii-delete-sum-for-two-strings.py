class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        DP = [0]*(len(s1)+1)
        for i in range(len(DP)):
            DP[i] = [0]*(len(s2)+1)
        
        for j in range(1, len(DP[0])):
            DP[0][j] = DP[0][j-1] + ord(s2[j-1])
        
        for i in range(1, len(DP)):
            DP[i][0] = DP[i-1][0] + ord(s1[i-1])

        for i in range(1,len(DP)):
            for j in range(1,len(DP[0])):
                if(s1[i-1] == s2[j-1]):
                    DP[i][j] = DP[i-1][j-1]
                else:
                    DP[i][j] = min(ord(s1[i-1])+DP[i-1][j],ord(s2[j-1])+DP[i][j-1])

        return DP[len(s1)][len(s2)]