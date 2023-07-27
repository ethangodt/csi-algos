function isValid(s: string): boolean {
    let stack = [];
    const getLast = (stack: string[]) => stack[stack.length - 1];
    for (let i = 0; i < s.length; i++) {
        if (['(', '{', '['].includes(s[i])) {
            stack.push(s[i])
        } else if (s[i] === ')' && getLast(stack) === '(') {
            stack.pop()
        } else if (s[i] === '}' && getLast(stack) === '{') {
            stack.pop()
        } else if (s[i] === ']' && getLast(stack) === '[') {
            stack.pop()
        } else {
            return false
        }
    }
    return stack.length === 0
};