package algo

func isValid(s string) bool {
	stack := []rune{}

	for _, c := range s {
		if c == '[' || c == '{' || c == '(' {
			stack = append(stack, c)
		} else {
			if len(stack) == 0 {
				return false
			}

			first := string(stack[len(stack)-1])
			second := string(c)
			switch first + second {
			case "{}", "[]", "()":
				stack = stack[:len(stack)-1]
			default:
				return false
			}
		}
	}

	return len(stack) == 0
}
