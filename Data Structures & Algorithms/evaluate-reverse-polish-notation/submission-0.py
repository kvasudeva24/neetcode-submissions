import math

class Solution:

    def evalRPN(self, tokens: List[str]) -> int:
        out = 0
        stack = []
        for token in tokens:
            if token not in ["+", "-", "*", "/"]:
                stack.append(int(token))
            elif token == "+":
                f = stack.pop()
                s = stack.pop()
                stack.append(f+s)
            elif token == "-":
                f = stack.pop()
                s = stack.pop()
                stack.append(s-f)
            elif token == "*":
                f = stack.pop()
                s = stack.pop()
                stack.append(f*s)
            elif token == "/":
                f = stack.pop()
                s = stack.pop()
                stack.append(int(s/f))

        return stack[-1]
