func numberOfBeams(bank []string) int {
    res, prev := 0, 0;
    
    for _, str := range bank {
        cur := 0;
        for _, c := range [] rune (str) {
            if c == '1' {
                cur += 1;
            }
        }
        if cur > 0 {
            res += prev * cur;
            prev = cur;
        }
    }

    return res;
}