#include <iostream>

using namespace std;

/*This Project is made by Ghada Hussien Arrefaey
Number : 213010050*/

int main()
{
    cout<<"Name : Ghada Hussien Arrefaey"<<endl;
    cout<<"Number : 213010050"<<endl;
    cout<<"This is CS200 project"<<endl<<endl<<endl;


    /*declaration of some variables used in the project*/
    int n,m,i,j,s,l,g,w,r,x,y,a,t=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0,sum1=0,sum,q=1;


    /*Entering number of rows and columns for matrix*/
    cout<<"Enter at least a 2x2 dimension for matrix:"<<endl;
    cout<<"Enter number of rows:"<<endl;
    cin>>n;
    cout<<"Enter number of columns:"<<endl;
    cin>>m;
    /* If number of rows and columns  of matrix is less than 2, asking user to enter the size of matrix again. */
    while(n<2||m<2)
    {
    cout<<"Enter number of rows:"<<endl;
    cin>>n;
    cout<<"Enter number of columns:"<<endl;
    cin>>m;
    }


    /*declaration of matrixes used in the project*/
    int matrix[n][m];
    int converse[n][m];
    int intersection[n][m];


    /* Storing elements of matrix. */
    cout<<"Enter elements of matrix"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
         cout<<"Matrix"<<"["<<i<<"]"<<"["<<j<<"]"<<"=";
         cin>>matrix[i][j];
        }
        cout<<endl;
    }


    /*Showing you the matrix you have entered*/
    cout<<"The matrix you have entered is:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
    }



     /*Summing each row alone to test if it was a function or not */
    for(i=0;i<n;i++)
    {
        s=0;
        for(j=0;j<m;j++)
        {
            s+=matrix[i][j];
        }
        /*if the result of summing of a row wasn't 1 (the condition to be a function) then it's not a function*/
         if(s!=1)
            {
                flag2=1;
                break;
            }
    }

    /*in case the summing of each row equals 1 then it's a function else it's not a function*/
    if(flag2==0)
        cout<<"it's a function because each element appears exactly once as the first element of an ordered pair"<<endl;
    else
        cout<<"it's not a function because there are some elements appear more than once as the first element in an ordered pair"<<endl;


    /*if it was a function we will test if it was bijective or not*/
    /*to be bijective then the summing of each row and each column must equal 1*/
    if(flag2==0)
    {
    for(i=0;i<n;i++)
    {
        /*the variable t is for the summing of each column,the variable s is for the summing of each row*/
        t=0;s=0;
        for(j=0;j<m;j++)
        {
            t+=matrix[j][i];
            s+=matrix[i][j];
        }
        /*if there was a summing of a row or a column that does not equal to 1 then the function is not bijective*/
         if(s!=1||t!=1)
            {
                flag3=1;
                break;
            }
    }
     /*if the summing of each row and column equal to 1 then the function is bijective else it's not bijective*/
    if(flag3==0)
        cout<<"it's bijective (one-to-one and onto)"<<endl;
    else
        cout<<"it's not bijective"<<endl;
    }


  /*if the matrix was square (number of rows=number of columns)*/
  if(m==n)
   {

    /*experimenting if the matrix was antisymmetric or not */
    for(i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
      {
          if(matrix[i][j]+matrix[j][i]>1)
          {
              flag1=1;
              break;
          }
      }
    }
    if(flag1==0)
        cout<<"it's antisymmetric"<<endl;
    else
        cout<<"it's not antisymmetric"<<endl;


    /*if the matrix was antisymmetric we bring out it's converse*/
    if(flag1==0)
    {
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             converse[i][j]=matrix[j][i];
         }
     }

     /*showing you the converse of your matrix*/
     cout<<"the converse of the matrix that you've entered is:"<<endl;
     for(i=0;i<n;i++)
     {
        for(j=0;j<m;j++)
        {
            cout<<converse[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
     }

     /*calculating the intersection of the main matrix and it's converse*/
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
                intersection[i][j]=matrix[i][j]*converse[i][j];

         }
     }

     /*showing you the intersection matrix*/
     cout<<"the intersection of the matrix that you've entered and it's converse:"<<endl;
     for(i=0;i<n;i++)
     {
        for(j=0;j<m;j++)
        {
            cout<<intersection[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
     }
    }
    /*Testing if it was a NULL graph*/
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum1+=matrix[i][j];
        }
    }
    if(sum1==0)
    {
        cout<<"It's a NULL graph"<<endl;
    }
    else{
    /*Testing if the matrix was a matrix of a simple graph*/
    for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
          {
              /*to be a simple graph then the matrix must not contain parallel edges(numbers bigger than 1)*/
              if(matrix[i][j]>1)
              {
                  flag5=1;
                  break;
              }
          }
      }
      for(i=0;i<n;i++)
      {
          /*to be a simple graph then the matrix must not contain loops*/
          if(matrix[i][i]!=0)
          {
              flag6=1;
              break;
          }
      }


      /*if the matrix contain no loops and no parallel edges then it's a simple graph else it's not a simple graph*/
       if(flag5==0&&flag6==0)
        cout<<"It's a simple graph because there are no loops and no parallel edges"<<endl;
       else{
        if(flag5==1&&flag6==1){
            cout<<"It's not a simple graph because the matrix contain parallel edges and loops"<<endl;}
        else {if(flag6==1){
        cout<<"It's not a simple graph because the matrix contain loops"<<endl;}
        else {if(flag5==1){
            cout<<"It's not a simple graph because the matrix contain parallel edges"<<endl;}
        }}}


      /*to be a multigraph then the matrix must contain parallel edges (numbers bigger than 1 in matrix)*/
      for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
          {
              if(matrix[i][j]>1)
              {
                  flag7=1;
                  break;
              }
          }
      }


      /*if there was parallel edges then the matrix is a multigraph matrix else it's not a multigraph*/
      if(flag7==1)
        cout<<"It's a multigraph because there are parallel edges "<<endl;
      else
        cout<<"It's not a multigraph because there are no parallel edges"<<endl;}


    /*calculating total degrees of each vertex*/
     cout<<"The total degrees for all vertices are:"<<endl;
      for(i=0;i<n;i++)
      {
        t=0;s=0;
        for(j=0;j<m;j++)
        {
            t+=matrix[i][j];
            s+=matrix[j][i];
            /*total degree = summing of column + summing of row*/
            sum=s+t;
        }
        cout<<"Total degree for vertex number"<<" "<<q<<" "<<"is:"<<sum<<endl;
        q++;
      }


      /*Entering length of the path*/
      cout<<"Enter length of the path that you want to check for:"<<endl;
      cin>>l;
      if(l>=1){
      /*calculating the matrix of number of paths that has the length that you have entered*/
      int path[n][n];
      int c[n][n];
      for(i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
        {
            path[i][j]=matrix[i][j];
        }

      }
      for(a=1;a<l;a++)
      {
          for(w=0;w<n;w++)
          {
              for(r=0;r<n;r++)
              {
                  c[w][r]=0;
                  for(g=0;g<n;g++)
                  {
                      c[w][r]+=matrix[w][g]*path[g][r];
                  }
              }
          }
          for (i=0;i<n;i++)
          {
              for(j=0;j<m;j++)
              {
                  path[i][j]=c[i][j];
              }
          }
      }


      /*showing you the matrix of number of paths with length that you've entered*/
      cout<<"matrix of number of paths with length"<<" "<<l<<":"<<endl;
      for(i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
        {
            cout<<path[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
      }
     do{
     cout<<"Enter two vertices that you want to check number of paths with length"<<" "<<l<<" between them:"<<endl;
     cout<<"Enter x : "<<endl;
     cin>>x;
     cout<<"Enter y : "<<endl;
     cin>>y;
     }while(x>n||y>n||x<=0||y<=0);
     cout<<"Number of paths with length"<<" "<<l<<" "<<"from"<<" "<<x<<" "<<"to"<<" "<<y<<" :"<<endl;
     x-=1;
     y-=1;

     cout<<path[x][y]<<endl;

    }

    }
    return 0;
}
