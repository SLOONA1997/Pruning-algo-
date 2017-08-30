#include<iostream>

int main()
{

int n;
std::cout<<"ENTER HOW MANY NODES YOU HAVE REQUIRED:  ";
std::cin>>n;

int a[n][n];


for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
         {
                  if(i==j)
                       a[i][j]=1000;
              else
                 {
                    std::cout<<std::endl<<"\t\t\t\t PRECAUTIONS \t"<<std::endl<<"\t\t\t\t-------------- \t"<<std::endl<<"  1. ENTER ONLY ALL WEIGHTS LESS THEN 500 OR AT MOST 500 SO THAT PROGRAM WOULD WORK PROPERLY : "<<std::endl;
     
   std::cout<<"  2. ENTER VALUE 0 WHERE U DON'T WANT COST B/W TWO VERTICES: "<<std::endl<<std::endl;
                   
             std::cout<<"ENTER COST BETWEEN "<<i+1<<" And "<<j+1<<" : ";
                std::cin>>a[i][j];
                       if(a[i][j]==0)
                              a[i][j]=1000;
                 a[j][i]=a[i][j];
         }
                                                  
      }

}


//TO FIND MINIMUM COST SEARCH FOR NODES
int T[10][2];

int mincost=a[0][1];
int k=0,l,min1,min2;
while(k<n)
{  
   l=k+1;

    while(l<n)
       {  
        if((a[k][l]<mincost)&&(a[k][l]!=0))
            {mincost=a[k][l];
            min1=k;
            min2=l;     
           } 
       l++;        
      }
           k++;
      }


T[0][0]=min1+1;
T[0][1]=min2+1;

//NEXT PROCEDURE

int near[10];

for(int u=0;u<n;u++)
{
    if((a[u][min2]==0)&&(a[u][min1]==0))
       near[u]=-1;    //Takes as Empty
   else if(((a[u][min2]<a[u][min1])&&(a[u][min2]!=0))||(a[u][min2]!=0&&a[u][min1]==0))
        near[u]=min2;
   else
     near[u]=min1;
}

near[min1]=0;
near[min2]=0;

//NEXT GAME STEP
int min;
std::cout<<T[0][0]<<"  "<<T[0][1]<<std::endl; 

for(int w=1;w<(n-1);w++)
{
         min=1000;
 //Start to find min
  int temp=0;
     for(int r=0;r<n;r++)   
      {
          if(near[r]==-1)
           min=1000;
          else if((near[r]!=0)&&(a[r][near[r]]<min&&a[r][near[r]]!=0))
                 {min=a[r][near[r]];
                T[w][0]=r+1;
                 T[w][1]=near[r]+1;
                 temp=r;
                    }
          }
mincost+=min;

near[temp]=0;
//end
//start
for(int m=0;m<n;m++)
{
  if((near[m]<0)&&(a[m][temp]!=0))
        near[m]=temp;
   else if((near[m]<0)&&(a[m][temp]==0))
        ;
else if((near[m]!=0)&&((a[m][near[m]]>a[m][temp])||(a[m][near[m]]==0&&a[m][temp]!=0)))
near[m]=temp;
    }
//end
std::cout<<T[w][0]<<"  "<<T[w][1]<<std::endl;
std::cout<<"weight : "<<mincost<<std::endl;
}


return 0;
}
