#include <bits/stdc++.h>

using namespace std;

string xorr(string a, string b){              // Function to calculate xor of 2 binary strings 
    int n = a.length();
    string c="";
    for(int i=0;i<n;i++){
        if(a[i]==b[i])c.push_back('0');
        else c.push_back('1');
    }
    return c;
}

string divide(string data, string div){          // Function to divide two binary strings, and it returns the remainder

    int div_len= div.length();

    int n= data.length();
    int x=div_len;
    string z = "";

    for(int i=0;i<x;i++)z.push_back(data[i]);
    string rem="";
    while(x<=n){
        if(z[0]=='0'){
            string tui="";
            for(int i=0;i<div_len;i++)tui.push_back('0');
            rem=xorr(z,tui);
        }
        else {
            rem=xorr(z,div);
        }
        if(x!=n){
            string wow= rem.substr(1,rem.length()-1);
            wow.push_back(data[x]);
            z=wow;
        }
        x++;

    }
    return rem.substr(1,rem.length()-1);

}

string generate_error(string data){      // To generate error in the received data 
    
    srand(time(NULL)); 
    int num = rand()%5;                  // I am generating errors at num number of positions 
    for(int i=0;i<num;i++){
        int pos = rand()%15;             // I am selecting those num positions randomly
        if(data[pos]=='0')data[pos]='1';
        else data[pos]='0';
    }

    return data;
}

string generate_frame(string &data, string& div){       // Function to generate the frame after appending the CRC bits
    string org_data=data;
    int k= data.length();
    int n= k+div.length()-1;
    for(int i=0;i<div.length()-1;i++)data.push_back('0');
    
    return org_data+divide(data,div);

}

bool check(string &data, string &div){        // Function which checks if the received data has errors or not by dividing it with p and checking the remainder
    string rem = divide(data,div);
    int n= rem.length();
    string xyz= "";
    for(int i=0;i<n;i++)xyz.push_back('0');
    return rem==xyz;

}

string generate_message(int length){     // Function to generate data randomly of given size
    string data= "";
    srand(time(NULL));
    for(int i=0;i<length;i++){
        
        int r= rand();
        if(r%2)data.push_back('1');
        else data.push_back('0');

    }
    return data;
}

int main(int argc, char**argv){
    
    string data,p;               // data is message and p is the given bits using which we will generate codeword
    int size=10;
    if(argc==3){
        data = argv[1];
        p = argv[2];
    }
    else{
        data = generate_message(size);
        p = "110101";
    }
    
    
    
    
    cout<<"Actual data:     "<<data<<endl;
    string encoded_data = generate_frame(data,p);


    
    cout<<"Codeword:        "<<encoded_data<<endl;
    string received_data = generate_error(encoded_data);
    cout<<"Received Data:   "<<received_data<<endl;
    if(check(received_data,p))cout<<"Successful, Data has no error"<<endl;
    else cout<<"Error........."<<endl;


}