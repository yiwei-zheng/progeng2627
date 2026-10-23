bool is_prime(int n){
    for (int i = 2; i * i <= n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int smallest_factor(int n){
    if(is_prime(n)){
        return 1;
    }
    for (int i = 2; i < n;i++){
        if (n % i == 0 && is_prime(i)){
            return i;
        }
    }
    return -1;
}