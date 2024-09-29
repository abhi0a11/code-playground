prime[1] = 0;
    for (int i = 2;i <= 100000;i++) {
        if (prime[i]) {
            for (int j = i * i;j <= 100000;j += i) {
                prime[j] = 0;
            }
        }
    }