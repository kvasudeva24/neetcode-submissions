class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        if len(s) == 0 or len(s) == 1:
            return False
        for letter in s:
            if len(stack) == 0:
                stack.append(letter)
            elif letter == ']' and stack[len(stack)-1] == '[':
                stack.pop()
            elif letter == ')' and stack[len(stack)-1] == '(':
                stack.pop()
            elif letter == '}' and stack[len(stack)-1] == '{':
                stack.pop()
            else:
                stack.append(letter)

        return (len(stack)==0)