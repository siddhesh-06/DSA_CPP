#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct students{
    //char name[10];
    string name;
    int rollNo;
    float sgpa;
};

class SE10{
    int n;
    students s[10];

    public:
    SE10(int no){
        n=no;
    };

    

    public:
    void input(){
        for(int i=0;i<n;i++){
            cout<<"======================"<<endl;

            cout<<"Enter the name: ";
            cin>>s[i].name;
            cout<<"Enter the Roll No: ";
            cin>>s[i].rollNo;
            cout<<"Enter the SGPA: ";
            cin>>s[i].sgpa;

            cout<<"======================"<<endl;
        }
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<"=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;

            cout<<"Your name is: "<<s[i].name<<endl;
            cout<<"Your Roll No is: "<<s[i].rollNo<<endl;
            cout<<"Your SGPA is: "<<s[i].sgpa<<endl;

            cout<<"=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        }
    }
    //roll no
    void bubble(){
        int n=n;
        int temp{0};
        
        //bubble sort
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){ 
            if(s[j+1].rollNo<s[j].rollNo){  
                students temp=s[j+1];
                s[j+1]=s[j];
                s[j]=temp;
                }
            }
        }
        
    }

    //name
    void insertion(){
        int j;
        students temp;
        for(int i=1;i<n;i++){
            temp=s[i];
            j=i-1;
            while(j>=0 && s[j].name>temp.name){
                s[j+1]=s[j];
                j=j-1;
            }
            
            s[j+1]=temp;
        }    
    }

    //sgpa
    void quickSort(){
        for(int i=0;i<n;i++){
            //float pivot=s[i].sgpa;//initial
            students pivot=s[i];

            for(int j=0;j<i;j++){
                if(s[j].sgpa>pivot.sgpa){
                    //float temp=s[j].sgpa;
                    students temp;
                    temp=s[j];
                    s[j]=pivot;
                    pivot=temp;
                }
            }

            for(int j=i+1;j<n;j++){
                if(s[j].sgpa<pivot.sgpa){
                    students temp=pivot;
                    pivot=s[j];
                    s[j]=temp;
                }
            }
            s[i]=pivot;
        }
    }
    //=============Toppers===============

    void topper(){
        quickSort();
        int j=0;
        for(int i=(n-1);i>=0;i--){
            j++;
            if(j<=3){
                cout<<j<<" Topper is: "<<s[i].name<<endl;
            }
        }
    }

    //=============Searching===============

    //sgpa search
    void linerSearch(float check){
        for(int i=0;i<n;i++){
            if(s[i].sgpa==check){
                cout<<"Name of student is: "<<s[i].name<<endl;
            }
        }
    }

    //name search
    int binarySearch(int left,int right,string x){

        insertion();
        while(left<=right){
            int mid=(left+right)/2;
            if(x==s[mid].name){
                return mid;
            }else if(x>s[mid].name){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
        
    }

    void displayBinary(int mid){
        for(int i=0;i<n;i++){
            if(s[mid].name==s[i].name){
                cout<<"Name is: "<<s[i].name<<endl;
                cout<<"Roll No is: "<<s[i].rollNo<<endl;
                cout<<"SGPA is: "<<s[i].sgpa<<endl;
            }
        }
        
    }    

};

int main(){
    int no{0};
    cout<<"Enter how many students: ";
    cin>>no;

    SE10 SE(no);

    SE.input();
    int a=1;
    while(a==1){
        int z,ans;
        cout<<"  "<<endl;
        cout<<"Enter your choice: "<<endl;
        cout<<"1.For sorting students by roll No: "<<endl;
        cout<<"2.For sorting students by names: "<<endl;
        cout<<"3.For sorting students by sgpa: "<<endl;
        cout<<"4.For finding first three topper: "<<endl;
        cout<<"5.For search the student by sgpa: "<<endl;
        cout<<"6.For search the student by name: "<<endl;
        cout<<"7.For exist: "<<endl;
        cin>>z;

        switch(z){
            case 1:
                SE.bubble();
                SE.display();
                break;
            case 2:
                SE.insertion();
                SE.display();
                break;
            case 3:
                SE.quickSort();
                SE.display();
                break;
            case 4:
                SE.topper();
                break;
            case 5:
                float checkSGPA;
                cout<<"Enter the sgpa: ";
                cin>>checkSGPA;
                SE.linerSearch(checkSGPA);
                break;
            case 6:
                char searchName[20];
                cout<<"Enter the name: ";
                cin>>searchName;
                ans=SE.binarySearch(0,no-1,searchName);
                SE.displayBinary(ans);
                break;    
            case 7:
                a=0;
                                        
        }
    }
    
    return 0;
}