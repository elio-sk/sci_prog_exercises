int main(){
    int n=77;
    cout << "Decimal to binary" << endl;
    string s = dec2bin(n);
    cout << bin2dec(s) << endl;

    string s1 = "10101";
    cout << "Binary to decimal" << endl;
    int k = bin2dec(s1);
    cout << bin2dec(s1) << endl;

    return 0;
}