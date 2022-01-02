#include<bits/stdc++.h>
using namespace std;
class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    public:
    Polynomial(){
        degCoeff=new int[5];
        for(int i=0;i<5;i++){
            degCoeff[i]=0;
        }
        capacity=5;
    }
    Polynomial(Polynomial const &p){
        this->capacity=p.capacity;
        degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            degCoeff[i]=p.degCoeff[i];
        }
    }
    void setCoefficient(int i,int el){
        // cout<<i<<endl;
        if(i<capacity){
            degCoeff[i]=el;
        }else{
            // cout<<i<<endl;
            int x=capacity;
            while(i>=x){
                x=x*2;
            }
            int *tmp=new int[x];
            for(int i=0;i<capacity;i++){
                tmp[i]=degCoeff[i];
            }
            for(int i=capacity;i<x;i++){
                tmp[i]=0;
            }
            delete []degCoeff;
            degCoeff=tmp;
            degCoeff[i]=el;
            capacity=x;
        }
    }
    void operator=(Polynomial const &p){
        this->capacity=p.capacity;
        degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            degCoeff[i]=p.degCoeff[i];
        }
    }
    Polynomial operator+(Polynomial const &p){
        Polynomial pn;
        int x=p.capacity>this->capacity?p.capacity:this->capacity;
        // pn.capacity=x;
        int i=0,j=0,k=0;
        while(i<this->capacity && j<p.capacity){
            pn.setCoefficient(k,this->degCoeff[i]+p.degCoeff[j]);
            i++;j++;k++;
        }
        while(i<this->capacity){
            pn.setCoefficient(k,this->degCoeff[i]);
            i++;k++;
        }
        while(j<p.capacity){
            pn.setCoefficient(k,p.degCoeff[j]);
            j++;k++;
        }
        return pn;
    }
    Polynomial operator-(Polynomial const &p){
        Polynomial pn;
        // int x=p.capacity>this->capacity?p.capacity:this->capacity;
        // pn.capacity=x;
        int i=0,j=0,k=0;
        while(i<this->capacity && j<p.capacity){
            pn.setCoefficient(k,this->degCoeff[i]-p.degCoeff[j]);
            i++;j++;k++;
        }
        while(i<this->capacity){
            pn.setCoefficient(k,this->degCoeff[i]);
            i++;k++;
        }
        while(j<p.capacity){
            pn.setCoefficient(k,0-p.degCoeff[j]);
            j++;k++;
        }
        return pn;
    }
    Polynomial operator*(Polynomial const &p){
        Polynomial pn;
        // cout<<pn.capacity;
        for(int i=0;i<this->capacity;i++){
            for(int j=0;j<p.capacity;j++){
                // cout<<pn.capacity<<" ";
                if(pn.capacity<=i+j){
                    cout<<i+j<<" ";
                    pn.setCoefficient(i+j,this->degCoeff[i]*p.degCoeff[j]);
                }else{
                    int x=pn.degCoeff[i+j];
                    x+=this->degCoeff[i]*p.degCoeff[j];
                    pn.setCoefficient(i+j,x);
                }
                // if(this->degCoeff[i]!=0 && p.degCoeff[j]!=0){
                //     cout<<i+j<<" ";
                // }
            }
        }
        return pn;
    }
    void print(){
        for(int i=0;i<this->capacity;i++){
            if(this->degCoeff[i]!=0){
                cout<<this->degCoeff[i]<<"x"<<i<<" ";
            }
        }
    }
};

// ************
 // Driver program to test below functions
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    // first.print();
    cout<<endl;
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
// ***************

// class Polynomial {
//     public:
//     int *degCoeff;      // Name of your array (Don't change this)
//     int capacity;
//     // Complete the class
//     public:
//     Polynomial(){
//         degCoeff=new int[5];
//         for(int i=0;i<5;i++){
//             degCoeff[i]=0;
//         }
//         capacity=5;
//     }
//     Polynomial(Polynomial const &p){
//         this->capacity=p.capacity;
//         degCoeff=new int[p.capacity];
//         for(int i=0;i<p.capacity;i++){
//             degCoeff[i]=p.degCoeff[i];
//         }
//     }
//     void setCoefficient(int i,int el){
//         if(i<capacity){
//             degCoeff[i]=el;
//         }else{
//             int x=capacity;
//             while(i>x){
//                 x=x*2;
//             }
//             // capacity=x;
//             int *tmp=new int[capacity];
//             for(int i=0;i<capacity;i++){
//                 tmp[i]=degCoeff[i];
//             }
//             for(int i=capacity;i<x;i++){
//                 tmp[i]=0;
//             }
//             delete []degCoeff;
//             degCoeff=tmp;
//             degCoeff[i]=el;
//             capacity=x;
//         }
//     }
//     void operator=(Polynomial const &p){
//         this->capacity=p.capacity;
//         degCoeff=new int[p.capacity];
//         for(int i=0;i<p.capacity;i++){
//             degCoeff[i]=p.degCoeff[i];
//         }
//     }
//     Polynomial operator+(Polynomial const &p){
//         Polynomial pn;
//         int x=p.capacity>this->capacity?p.capacity:this->capacity;
//         // pn.capacity=x;
//         int i=0,j=0,k=0;
//         while(i<this->capacity && j<p.capacity){
//             pn.setCoefficient(k,this->degCoeff[i]+p.degCoeff[j]);
//             i++;j++;k++;
//         }
//         while(i<this->capacity){
//             pn.setCoefficient(k,this->degCoeff[i]);
//             i++;k++;
//         }
//         while(j<p.capacity){
//             pn.setCoefficient(k,p.degCoeff[j]);
//             j++;k++;
//         }
//         return pn;
//     }
//     Polynomial operator-(Polynomial const &p){
//         Polynomial pn;
//         // int x=p.capacity>this->capacity?p.capacity:this->capacity;
//         // pn.capacity=x;
//         int i=0,j=0,k=0;
//         while(i<this->capacity && j<p.capacity){
//             pn.setCoefficient(k,this->degCoeff[i]-p.degCoeff[j]);
//             i++;j++;k++;
//         }
//         while(i<this->capacity){
//             pn.setCoefficient(k,this->degCoeff[i]);
//             i++;k++;
//         }
//         while(j<p.capacity){
//             pn.setCoefficient(k,0-p.degCoeff[j]);
//             j++;k++;
//         }
//         return pn;
//     }
//     Polynomial operator*(Polynomial const &p){
//         Polynomial pn;
//         for(int i=0;i<this->capacity;i++){
//             for(int j=0;j<p.capacity;j++){
//                 pn.setCoefficient(i+j,this->degCoeff[i]*p.degCoeff[j]);
//             }
//         }
        
//     }
//     void print(){
//         for(int i=0;i<this->capacity;i++){
//             if(this->degCoeff[i]!=0){
//                 cout<<this->degCoeff[i]<<"x"<<i<<" ";
//             }
//         }
//     }
// };
