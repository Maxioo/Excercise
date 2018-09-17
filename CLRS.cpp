/*      Introduction to Algorithm   */
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std;


// 1.插入排序

void insertSort()
{
    ifstream fin("data");
    if(fin.bad()){
        cout<<"打开文件出错"<<endl;
        return ;
    }
    vector<int> data;
    string stringTemp;

    while(1){
        fin>>stringTemp;
        if(fin.eof())
            break;
        data.push_back(atoi(stringTemp.c_str()));
    }
    for(vector<int>::size_type i = 0; i != data.size(); i++)
        cout<<data[i]<<" ";

    int key;
    for(vector<int>::size_type i = 1; i != data.size(); i++){
        key = data[i];
        for(vector<int>::size_type j = i-1; j >= 0; j--){
            if(data[j] > key)
                data[j+1] = data[j];
            else{
                data[j+1] = key;
                break;
            }
        }
    }
    cout<<"排序之后的结果为"<<endl;
    for(vector<int>::size_type i = 0; i != data.size(); i++)
        cout<<data[i]<<" ";

    return ;
}
                
            

// 2.线性查找算法

void linerSearch()
{
    int aimInt;
    cout<<"请输入你需要查找的数据"<<endl;
    cin>>aimInt;
    ifstream fin("data");
    if(fin.bad())
    {
        cout<<"打开文件出错"<<endl;
        return;
    }
    vector<int> data;
    string stringTemp;
    while(!fin.eof())
    {
        fin>>stringTemp;
        data.push_back(atoi(stringTemp.c_str()));
	cout<<stringTemp<<" ";
    }
    for(vector<int>::iterator i = data.begin(); i != data.end(); i++)
    {
        if(*i == aimInt)
	{
            cout<<"这是第"<<static_cast<int>(i-data.begin())<<"个数"<<endl;
	    return ;
	}
    }
    cout<<"没有找到该数";
    return ;
}

//3.相加两个二进制数


void addBinaryNum()
{
    ifstream fin1("data1");
    ifstream fin2("data2");
    if (fin1.bad()||fin2.bad())
    {
        cout<<"打开文件出错"<<endl;
        return ;
    }
    vector<int> data1;
    vector<int> data2;
    string stringTemp;
    int numTemp;
    getline(fin1,stringTemp);
    cout<<"第一个二进制的数为"<<stringTemp<<endl;
    for(string::size_type i = 0; i!=stringTemp.length(); i++){
        numTemp = stringTemp[i]-48;
        data1.push_back(numTemp);
    }
    getline(fin2,stringTemp);
    cout<<'\n'<<"第二个二进制数为"<<stringTemp<<endl;
    for(string::size_type i = 0; i!=stringTemp.length(); i++){
        numTemp = stringTemp[i]-48;
        data2.push_back(numTemp);
    }
    int minNum = data1.size() > data2.size() ? data2.size() : data1.size();
    numTemp = 0;
    vector<int> result;
    for(int i = 0; i!= minNum; i++){
        result.push_back((numTemp+data1[i]+data2[i])%2);
        numTemp = (numTemp+data1[i]+data2[i])/2;
    }
    if(data1.size() > data2.size()){
        for(int i = minNum; i!=data1.size();i++){
            result.push_back((numTemp+data1[i])%2);
            numTemp = (numTemp+data1[i])/2;
        }
    }
    else{
        for(int i = minNum; i!= data2.size(); i++){
            result.push_back((numTemp+data2[i])%2);
            numTemp = (numTemp+data2[i])/2;
        }
    }
    cout<<'\n'<<"运算结果为"<<endl;
    for(vector<int>::size_type i = 0; i != result.size(); i++){
        cout<<result[i];
    }
    return ;
}


// 4.选择排序

void exchange(int& a,int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selectionSort()
{
    ifstream openfile("data");
    if (openfile.bad())
    {
        cout<<"打开文件出错"<<endl;
        return;
    }
    vector<int> data;
    string stringTemp;
    while(1)
    {
        openfile >> stringTemp;
        if(openfile.eof())
            break;
        data.push_back(atoi(stringTemp.c_str()));
    }
    vector<int>::size_type tempIndex = 0;
    int min;
    for(vector<int>::size_type i = 0; i != data.size()-1; i++)
    {
        min = data[i];
        tempIndex = i;
        for(vector<int>::size_type j = i; j != data.size(); j++)
        {
            if(data[j]<min)
            {
                min = data[j];
                tempIndex = j;
            }
        }
        exchange(data[i],data[tempIndex]);
    }
    
    for(vector<int>::iterator i = data.begin(); i != data.end(); i++)
    {
        cout<<*i<<" ";
    }
    return ;
}

// 5.二路并归排序

void Merge(vector<int>& data,int p,int q,int r)
{
    int n = q;
    vector<int> leftData,rightData;
    for(vector<int>::size_type i = p; i != n; i++){
        leftData.push_back(data[i]);
    }
    for(vector<int>::size_type i = n; i != r; i++){
        rightData.push_back(data[i]);
    }
    int n1 = leftData.size();
    int n2 = rightData.size();
    int tempn1=0,tempn2=0;
    while(true){
        if(tempn1 ==n1 || tempn2 == n2)
            break;
        if(leftData[tempn1] > rightData[tempn2]){
            data[p+tempn2+tempn1] = rightData[tempn2];
            tempn2++;
        } else {
            data[p+tempn1+tempn2] = leftData[tempn1];
            tempn1++;
        }
    }
    if(tempn1 == n1){
        for(int i = tempn2; i != n2; i++)
            data[p+i+n1] = rightData[i];
    } else {
        for(int i = tempn1; i != n1; i++)
            data[p+i+n2] = leftData[i];
    }
}

void doMergeSort(vector<int>&data,int q,int r)
{
    if(q == r-1)
        return ;
    int n = (q+r)/2;
    doMergeSort(data,q,n);
    doMergeSort(data,n,r);
    Merge(data,q,n,r);
}

void mergeSort()
{
    ifstream fin("data");
    if(fin.bad()){
        cout<<"打开文件"<<endl;
        return ;
    }
    vector<int> data;
    string stringTemp;
    
    while(1){
        fin >> stringTemp;
        if(fin.fail())
            break;
        data.push_back(atoi(stringTemp.c_str()));
    }
    doMergeSort(data,0,data.size());
    for(vector<int>::size_type i = 0; i != data.size(); i++){
        cout<<data[i]<<" ";
        }
    return ;
}

// 6.二路并归查找（Answer)

void mergeSearch()
{
    ifstream fin("data");
    if(fin.bad()){
        cout<<"打开文件出错"<<endl;
        return ;
    }
    int aimInt;
    cout<<"请输入需要查找的数据"<<endl;
    cin>>aimInt;
    vector<int> data;
    string stringTemp;

    while(1){
        fin >> stringTemp;
        if(fin.fail())
            break ;
        data.push_back(atoi(stringTemp.c_str()));
    }
    
    int left = 0, right = data.size();
    int mid = (left + right)/2;
    while(1){
        if(left == right&&data[left] != aimInt){
            cout<<"找不到该数"<<endl;
            return ;
        }
        if (data[mid] == aimInt){
            cout<<"该数是第"<<mid+1<<"个"<<endl;
            return ;
        } else if(data[mid] < aimInt){
            left = mid;
            mid = (left + right)/2;
        } else {
            right = mid;
            mid = (left + right)/2;
        }
    }
}

// 7.查找逆序数

int merge(int A[], int p, int q, int r) {
    int i, j, k, inversions = 0;

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++) L[i] = A[p + i];
    for (j = 0; j < n2; j++) R[j] = A[q + j + 1];

    for(i = 0, j = 0, k = p; k <= r; k++) {
        if (i == n1) {
            A[k] = R[j++];
        } else if (j == n2) {
            A[k] = L[i++];
        } else if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            inversions += n1 - i;
        }
    }

    return inversions;
}

int merge_sort(int A[], int p, int r) {
    if (p < r) {
        int inversions = 0;
        int q = (p + r) / 2;
        inversions += merge_sort(A, p, q);
        inversions += merge_sort(A, q + 1, r);
        inversions += merge(A, p, q, r);
        return inversions;
    } else {
        return 0;
    }
}

int main()
{
    //insertSort();
    //linerSearch();
    //addBinaryNum();
    //selectionSort();
    //mergeSort();
    mergeSearch();
}
