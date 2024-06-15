from collections import deque


class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        qR = deque()
        qD = deque()

        for i in range(n):
            if senate[i] == 'R':
                qR.append(i)
            else:
                qD.append(i)

        while qR and qD:
            indexR = qR.popleft()
            indexD = qD.popleft()
            if indexR < indexD:
                qR.append(indexR + n)
            else:
                qD.append(indexD + n)

        return "Dire" if not qR else "Radiant"
