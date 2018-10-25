/*      Introduction to Algorithm   */
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<ctime>
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

//8.最大子串 暴力法

const int INF = 10000000;
typedef vector<int>::size_type sizeType;
void maxSubBrute()
{
    clock_t begin, end;
    begin = clock();
    freopen("data.in","rb",stdin);
    vector<int> data;
    int temp;
    while(scanf("%d",&temp) == 1)
        data.push_back(temp);
    vector<int>::size_type dLen = data.size(), maxi = 0, maxj = 0;
    int sumI = -INF, sum = 0;
    for(vector<int>::size_type i = 0; i != dLen; i++)
    {
        sum = 0;
        for(vector<int>::size_type j = i; j != dLen; j++)
        {
            sum += data[j];
            if(sumI < sum)
            {
                maxi = i;
                maxj = j;
                sumI = sum;
            }
        }
    }
    vector<int> result;
    result.push_back(maxi);
    result.push_back(maxj);
    result.push_back(sumI);
    printf("The result is %d %d %d\n",result[0],result[1],result[2]);
    end = clock();
    printf("The time is %.3f\n",(double)(end - begin)/CLOCKS_PER_SEC);
}

// 9.最大子串，分冶法

vector<int> findMaxCrossingSub(vector<int>& data,sizeType low,sizeType mid,sizeType high)
{
    int leftSum = -INF;
    int sum = 0;
    vector<int> result;
    int leftindex,rightindex;
    for(sizeType i = mid; i >= low;i--)
    {
        sum += data[i];
        if(leftSum < sum)
        {
            leftSum = sum;
            leftindex = i;
        }
        if(i == low)
            break;
    }
    int rightSum = -INF;
    sum = 0;
    for(sizeType i = mid+1; i <= high; i++)
    {
        sum += data[i];
        if(rightSum < sum)
        {
            rightSum = sum;
            rightindex = i;
        }
    }
    result.push_back(leftindex);
    result.push_back(rightindex);
    result.push_back(leftSum+rightSum);
    return result;
}

vector<int> findMaxSub(vector<int>& data, sizeType low, sizeType high)
{
    vector<int> result(3);
    if(low == high)
    {
        result[0] = low;
        result[1] = low;
        result[2] = data[low];
        return result;
    }
    sizeType mid = (low+high)/2;

    vector<int> leftRe = findMaxSub(data,low,mid);
    vector<int> rightRe = findMaxSub(data,mid+1,high);
    vector<int> crossRe = findMaxCrossingSub(data,low,mid,high);
    if(leftRe[2] >= rightRe[2] && leftRe[2] >= crossRe[2])               //没考虑相等的情况
        return leftRe;
    else if(rightRe[2] >= leftRe[2] && rightRe[2] >= crossRe[2])
        return rightRe;
    else if(crossRe[2] >= leftRe[2] && crossRe[2] >= leftRe[2])
        return crossRe;
}

void findMaxSubRecurr()
{
    clock_t begin, end;
    begin = clock();
    freopen("data.in","rb",stdin);
    vector<int> data;
    int temp;
    while(scanf("%d",&temp) == 1)
        data.push_back(temp);
    vector<int> result;
    result = findMaxSub(data, 0, data.size()-1);
    printf("The result is %d %d %d\n",result[0],result[1],result[2]);
    end = clock();
    printf("The time is %.3f\n",(double)(end - begin)/CLOCKS_PER_SEC);
}


// 10.最大子串 依旧是O(n^2)

void findMaxSubNoLiner()
{
    clock_t begin, end;
    begin = clock();
    freopen("data.in","rb",stdin);
    vector<int> data;
    int temp;
    while(scanf("%d",&temp) == 1)
          data.push_back(temp);
    vector<int> result(3);
    int dataSize = data.size();
    int sumE = data[0];
    int sum,maxi = 0, maxj = 0;
    for(int i = 0; i != dataSize -1 ; i++)
    {
        sum = 0;
        for(int j = i+1; j >= maxi; j--)
        {
            sum += data[j];
            if(sum > sumE)
            {
                sumE = sum;
                maxi = j;
                maxj = i+1;
            }
        }
    }
    result[0] = maxi;
    result[1] = maxj;
    result[2] = sumE;
    printf("The result is %d %d %d\n",maxi,maxj,sumE);
    end = clock();
    printf("The time is %.3f\n",(double)(end - begin)/CLOCKS_PER_SEC);
}

void findMaxSubLiner()
{
    clock_t begin,end;
    begin = clock();
    freopen("data.in","rb",stdin);
    vector<int> data;
    int temp;
    while(scanf("%d",&temp) == 1)
        data.push_back(temp);
    int dataSize = data.size();
    vector<int> S;
    int maxi = 0;
    int sum = 0, sumE = -INF, maxj = 0;
    int tempi = 0;
    for(int i = 0; i != dataSize; i++)
    {
        sum += data[i];
        if(sum < 0)
        {
            sum = 0;
            tempi = i+1;
        }
        if(sumE < sum)
        {
            sumE = sum;
            maxj = i;
            maxi = tempi;
        }
    }
    printf("The result is %d %d %d\n",maxi,maxj,sumE);
    end = clock();
    printf("The time is %.3f\n",(double)(end - begin)/CLOCKS_PER_SEC);
}
          
int main()
{
    //insertSort();
    //linerSearch();
    //addBinaryNum();
    //selectionSort();
    //mergeSort();
    //mergeSearch();
    maxSubBrute();
    findMaxSubRecurr();
    findMaxSubNoLiner();
    findMaxSubLiner();
}
