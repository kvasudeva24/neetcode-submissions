class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [[p,s] for p,s in zip(position, speed)]
        pair.sort()
        n=len(pair)

        stack = []

        for i in range(n-1, -1, -1):
            time = (target - pair[i][0])/pair[i][1]
            if stack:
                if time <= stack[-1]:
                    continue
                else:
                    stack.append(time)
            else:
                stack.append(time)
        
        return len(stack)
            

