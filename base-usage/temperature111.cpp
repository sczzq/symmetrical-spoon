#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define  NZ   ( 320 )
#define  NY   ( 160 )
#define  NX   ( 160 )
#define  NZ1  ( NZ+1 )
#define  NY1  ( NY+1 )
#define  NX1  ( NX+1 )

#define R ( 20.0 )
#define NZ_c (NZ/2.0)
#define NY_c (NY/2.0)
#define NX_c (NX/2.0)


#define rhol 1.0
#define rhog 1.0
#define rhom  ( 0.5*(rhol+rhog) )

#define PI  3.1415926535897932
#define ww (2.0*PI/NX)

#define phil ( 1.0 )
#define phig ( 0.0 )
#define phim ( 0.5*(phil+phig) )

#define Tc   0
#define Th   32
#define Tref 10
#define T00 4.0

#define sigmaT   (-0.0001)
#define sigmaref (0.0025)

#define D 2.0
#define rcs1 4.0
#define cs1 (1.0/4)
#define rcs2 3.0
#define cs2 (1.0/3.0)

#define MM 1.0
#define lamda1 0.2
#define lamda2 0.2
#define ca  1.0
#define cb  1.0

 
#define     niul  (0.2)
#define     niug  (niul*MM)

#define  tau_gl (3*(niul)+0.5)
#define  tau_gg (3*(niug)+0.5)
#define  ww_gg  (1.0/(3*(niug)+0.5))
#define  ww_gl  (1.0/(3*(niul)+0.5))

double w1[7]={ 1.0/4.0, 1.0/8.0 , 1.0/8.0, 1.0/8.0, 1.0/8.0, 1.0/8.0, 1.0/8.0};
double w2[15]={ 2.0/9, 1.0/9 , 1.0/9, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/72.0, 1.0/72.0, 1.0/72.0, 1.0/72.0, 1.0/72.0, 1.0/72.0, 1.0/72.0, 1.0/72.0};
int    e1[7][3]={{0,0,0}, {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
int    e2[15][3]={{0,0,0}, {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}, {1,1,1}, {-1,-1,-1},{1,1,-1},{-1,-1,1},{1,-1,1},{-1,1,-1},{1,-1,-1},{-1,1,1}};
int    rp1[7]={0,2,1,4,3,6,5};
int    rp2[15]={0,2,1,4,3,6,5,8,7,10,9,12,11,14,13};
double f[NZ1][NY1][NX1][7], F[NZ1][NY1][NX1][7], g[NZ1][NY1][NX1][15], G[NZ1][NY1][NX1][15], h[NZ1][NY1][NX1][7], H[NZ1][NY1][NX1][7];
double ux[NZ1][NY1][NX1], uy[NZ1][NY1][NX1],uz[NZ1][NY1][NX1], ux0[NZ1][NY1][NX1], uy0[NZ1][NY1][NX1],uz0[NZ1][NY1][NX1],phi0[NZ1][NY1][NX1],Fw[NZ1][NY1][NX1],Fn[NZ1][NY1][NX1];
double phi[NZ1][NY1][NX1], rho[NZ1][NY1][NX1], p[NZ1][NY1][NX1], mu[NZ1][NY1][NX1],B[NZ1][NY1][NX1], T[NZ1][NY1][NX1],T0[NZ1][NY1][NX1];
double dnx[NZ1][NY1][NX1], dny[NZ1][NY1][NX1], dnz[NZ1][NY1][NX1],sigma[NZ1][NY1][NX1],beta[NZ1][NY1][NX1], Kappa[NZ1][NY1][NX1];
double tau_g[NZ1][NY1][NX1],ww_g[NZ1][NY1][NX1],niu[NZ1][NY1][NX1],lamda[NZ1][NY1][NX1],tau_h[NZ1][NY1][NX1],ww_h[NZ1][NY1][NX1];
double tau_f, ww_f;
double dx, dt, c, rdx, rdt, rc, rcc;
double M, A,ggy;
int j, k, i,m, jp, kp,mp,kpp,t;

double feq(double ux, double uy, double uz, double phi, int i);
double geq(double ux, double uy, double uz, double p, double rho, int i);
double heq(double ux, double uy, double uz, double T, int i);
double weq(double ux, double uy, double uz, int i);

void init(); 
void collision();
void stream();
void evolution();
void OutPutData(int t);
void output1(int t);

int main()
{
	int tmax,t,TT,mm;
	double error,temp1,temp2,rho_tal2;
	tmax=0;
	t=0;
    
	init();
	OutPutData(t);
    
AA:	printf("please input the interate steps:\n");
	scanf("%d",&TT);
	tmax+=TT;
	while(t<tmax)
	{
		t++;
	    evolution();
	
		if(t%1==0)
		{
		   rho_tal2=0;
		   temp1=temp2=0;
	       for(j=0; j<=NZ; j++)
		   {
		      for(k=0; k<=NY; k++)
			  { 
				 for(m=0;m<=NX;m++)
				 {
					rho_tal2+=phi[j][k][m];

					temp1+=fabs(phi[j][k][m]-phi0[j][k][m]);
					temp2+=fabs(phi[j][k][m]);
				 }
				 
			  }
		   }
		   error=temp1/temp2;
		   printf("t=%d rho[NZ/2][NY/2][NX/2]=%lf rho_tal2=%lf error=%e\n", t, rho[NZ/2][NY/2][NX/2], rho_tal2, error);
		   OutPutData(t);
		   output1(t);
		}
	}
   printf("continue?(yes=1,no=0)\n");
   scanf("%d",&mm);
   if(mm) goto AA;
   OutPutData(t);
   output1(t);
   return 0;
}

double feq(double ux, double uy, double uz, double phi, int i)
{
	double feq, eu;

	eu=e1[i][0]*ux+e1[i][1]*uy+e1[i][2]*uz;	
	feq=phi*w1[i]*(1.0+rcs1*eu); 
	
	return feq;
}

double heq(double ux, double uy, double uz, double T, int i)
{
	double heq,eu;
	eu=e1[i][0]*ux+e1[i][1]*uy+e1[i][2]*uz;
	heq=T*w1[i]*(1.0+rcs1*eu);
	return heq;
}

double geq(double ux, double uy, double uz, double p, double rho, int i)
{ 
	double geq, uv, eu, su;
	eu=e1[i][0]*ux+e1[i][1]*uy+e1[i][2]*uz;
	uv=ux*ux+uy*uy+uz*uz;
	su=w2[i]*(3.0*eu+4.5*eu*eu-1.5*uv);
	if(i==0)
	{
		geq=rcs2*p*(w2[0]-1.0)+rho*su;
	}
	else
	{
		geq=rcs2*p*w2[i]+rho*su;
	}
	return geq;
}

double weq(double ux, double uy, double uz, int i)
{
    double weq, uv, eu;

	uv=ux*ux+uy*uy+uz*uz;
	eu=e2[i][0]*ux+e2[i][1]*uy+e2[i][2]*uz;

    weq=w2[i]*(1.0+3.0*eu+4.5*eu*eu-1.5*uv);

	return weq;
}

void init()
{
    double rho_tal1,  mu0, DDphi,xx;

    c=1.0;
	dx=1.0;
	dt=dx/c;
   

	M=0.05;	
	tau_f=M/(cs1*dt);   
	ww_f=1.0/(tau_f+0.5);
	A=-((tau_f+0.5)*dt*cs1);
	
	
	for(j=0; j<=NZ; j++)
	{
	   for(k=0; k<=NY; k++)
	   { 
		   for(m=0;m<=NX;m++)
		   {
			   Fn[j][k][m]=0.0;//5.0*0.0000001;
			
				T[j][k][m]=0.1*j;
			
				sigma[j][k][m]=sigmaref+sigmaT*(T[j][k][m]-Tref);
				beta[j][k][m]=12*sigma[j][k][m]/(D*(phil-phig)*(phil-phig)*(phil-phig)*(phil-phig));  
				Kappa[j][k][m]=1.5*D*sigma[j][k][m]/((phil-phig)*(phil-phig));
				
				xx=R-sqrt( (m-NX_c)*(m-NX_c)+(k-NY_c)*(k-NY_c)+(j-NZ_c)*(j-NZ_c) );              
		 	    phi[j][k][m]=0.5*(phil+phig)+0.5*(phil-phig)*tanh(2*xx/D);
				
			
				p[j][k][m]=0.0;		   
				ux[j][k][m]=0.0;
				uy[j][k][m]=0.0; 
				uz[j][k][m]=0.0;
				
				ux0[j][k][m]=ux[j][k][m];
				uy0[j][k][m]=uy[j][k][m];
				uz0[j][k][m]=uz[j][k][m];
				phi0[j][k][m]=phi[j][k][m];

				rho[j][k][m]=(phi[j][k][m]-phig)*(rhol-rhog)/(phil-phig)+rhog;	
				lamda[j][k][m]=(phi[j][k][m]-phig)*(lamda1-lamda2)/(phil-phig)+lamda2;
				tau_h[j][k][m]=lamda[j][k][m]/(ca*cs1*dt);
				ww_h[j][k][m]=1.0/(tau_h[j][k][m]+0.5);
		  // niu[j][k]=(niu[j][k]-phig)*(niul-niug)/(phil-phig)+niug;	
				niu[j][k][m]=(niul*niug*(phil-phig))/((phi[j][k][m]-phig)*niug+(phil-phi[j][k][m])*niul);
				tau_g[j][k][m]=niu[j][k][m]*rcs2/dt+0.5;
				ww_g[j][k][m]=1.0/tau_g[j][k][m];
				B[j][k][m]=cs1*(tau_f)*dt*4.0*phi[j][k][m]*(1.0-phi[j][k][m])/D;	
		   }			
	   }
	}

	

	rho_tal1=0;
	for(j=0; j<=NZ; j++)
	{
		for(k=0; k<=NY; k++)
		{
			for(m=0;m<=NX;m++)
			{
				for(i=0; i<7; i++)
				{
					f[j][k][m][i]=feq(ux[j][k][m], uy[j][k][m], uz[j][k][m], phi[j][k][m], i);
					h[j][k][m][i]=heq(ux[j][k][m], uy[j][k][m], uz[j][k][m], T[j][k][m], i);					
				}
				for(i=0; i<15; i++)
				{					
					g[j][k][m][i]=geq(ux[j][k][m], uy[j][k][m], uz[j][k][m], p[j][k][m], rho[j][k][m], i);
				}
				rho_tal1+=phi[j][k][m];
			}
					
		}
	}


	//计算 mu   
	for(j=0; j<=NZ; j++)
	{
	    for(k=0; k<=NY; k++)
		{
			for(m=0;m<=NX;m++)
			{
				DDphi=0.0;
				for(i=1; i<15; i++)
				{
					jp=j+e2[i][2];
					kp=(k+e2[i][1]+NY)%(NY);
					mp=(m+e2[i][0]+NX)%(NX);
					if(jp>=0&&jp<=NY)
					{
						DDphi+=w2[i]*(phi[jp][kp][mp]-phi[j][k][m]);
					}
					else
					{
						DDphi+=w2[i]*(phi[j][k][m]-phi[j][k][m]);
					} 
				 		
				}
				mu0=4.0*beta[j][k][m]*(phi[j][k][m]-phil)*(phi[j][k][m]-phig)*(phi[j][k][m]-phim);
				mu[j][k][m]=mu0-Kappa[j][k][m]*2.0*rcs2*DDphi;
			}
			
		}
	}

    printf("rho_tal1=%lf tau_f=%lf tau_gg=%lf M=%lf D=%lf sigma[NZ/2][NY/2][NX/2]=%lf beta[NZ/2][NY/2][NX/2]=%lf Kappa[NZ/2][NY/2][NX/2]=%lf\n",rho_tal1, tau_f, tau_gg, M, D, sigma[NZ/2][NY/2][NX/2], beta[NZ/2][NY/2][NX/2], Kappa[NZ/2][NY/2][NX/2]);
}


void collision()
{
    double Dphix, Dphiy, Dphiz, Dphixyz,cphix, cphiy, cphiz, GG,Fa,Fsx,Fsy,Fsz;
	double DTx, DTy,DTz, dTux, dTuy, dTuz,dTuxy;
	double HH,Hx;
    double wu;
	double FF,Cx,Cy,Cz,Cxyz,dphiux,dphiuy,dphiuz,dphiuxyz;
	
	for(j=0; j<=NZ; j++) 
    {
		for(k=0; k<=NY; k++)
		{ 
			for(m=0;m<=NX;m++)
			{
				Dphix=Dphiy=0.0;
				DTx=DTy=0.0;
			
				for(i=1; i<7; i++)
				{
					jp=j+e1[i][2];
					kp=(k+e1[i][1]+NY)%(NY);
					mp=(m+e1[i][0]+NX)%(NX);
					if(jp>=0&&jp<=NY)
					{
						/*Dphix+=3.0*w[i]*phi[jp][kp]*e[i][0];
						Dphiy+=3.0*w[i]*phi[jp][kp]*e[i][1];*/
						DTx+=rcs1*w1[i]*T[jp][kp][mp]*e1[i][0];
						DTy+=rcs1*w1[i]*T[jp][kp][mp]*e1[i][1];
						DTz+=rcs1*w1[i]*T[jp][kp][mp]*e1[i][2];
					}
					else
					{
						DTx+=rcs1*w1[i]*T[j][k][m]*e1[i][0];
						DTy+=rcs1*w1[i]*T[j][k][m]*e1[i][1];
						DTz+=rcs1*w1[i]*T[j][k][m]*e1[i][2];
				  /* Dphix+=3.0*w[i]*phi[j][k]*e[i][0];
			       Dphiy+=3.0*w[i]*phi[j][k]*e[i][1];
						DTx+=rcs1*w[i]*T[j][k]*e[i][0];
						DTy+=rcs1*w[i]*T[j][k]*e[i][1];*/
					}
				}
				/*Dphixy=sqrt(Dphix*Dphix+Dphiy*Dphiy);*/
				dphiux=(phi[j][k][m]*ux[j][k][m]-phi0[j][k][m]*ux0[j][k][m])/dt;
				dphiuy=(phi[j][k][m]*uy[j][k][m]-phi0[j][k][m]*uy0[j][k][m])/dt;
				dphiuz=(phi[j][k][m]*uz[j][k][m]-phi0[j][k][m]*uz0[j][k][m])/dt;
				dTux=(T[j][k][m]*ux[j][k][m]-T0[j][k][m]*ux0[j][k][m])/dt;
				dTuy=(T[j][k][m]*uy[j][k][m]-T0[j][k][m]*uy0[j][k][m])/dt;
				dTuz=(T[j][k][m]*uz[j][k][m]-T0[j][k][m]*uz0[j][k][m])/dt;
				Cx=0.0;
				Cy=0.0;
				Cz=0.0;
			
				for(i=1; i<7; i++)
				{
					Cx+=e1[i][0]*(f[j][k][m][i]-feq(ux[j][k][m],uy[j][k][m],uz[j][k][m],phi[j][k][m],i));
					Cy+=e1[i][1]*(f[j][k][m][i]-feq(ux[j][k][m],uy[j][k][m],uz[j][k][m],phi[j][k][m],i));
					Cz+=e1[i][2]*(f[j][k][m][i]-feq(ux[j][k][m],uy[j][k][m],uz[j][k][m],phi[j][k][m],i));
					/*DTx+=e[i][0]*(h[j][k][i]-heq(u[j][k], v[j][k], T[j][k], i));
					DTy+=e[i][1]*(h[j][k][i]-heq(u[j][k], v[j][k], T[j][k], i));*/
				}
				Cx=Cx+0.5*dt*dphiux;
				Cy=Cy+0.5*dt*dphiuy;
				Cz=Cz+0.5*dt*dphiuz;
			 
				Cxyz=sqrt(Cx*Cx+Cy*Cy+Cz*Cz);
				Dphixyz=-(Cxyz+B[j][k][m])/A;			 
				Dphix=Cx/(A+(B[j][k][m]/(Dphixyz+exp(-10.0))));
				Dphiy=Cy/(A+(B[j][k][m]/(Dphixyz+exp(-10.0))));
				Dphiz=Cz/(A+(B[j][k][m]/(Dphixyz+exp(-10.0))));
				/*DTx=(DTx+0.5*dt*dTu)*rcs2*ww_h[j][k]/dt;
				DTy=(DTy+0.5*dt*dTv)*rcs2*ww_h[j][k]/dt;*/
				for(i=0;i<7;i++)
				{
					FF=(e1[i][0]*Dphix+e1[i][1]*Dphiy+e1[i][2]*Dphiz)/(Dphixyz+exp(-10.0));
					dTuxy=rcs1*(1.0-0.5*ww_h[j][k][m])*(e1[i][0]*dTux+e1[i][1]*dTuy+e1[i][2]*dTuz);
					Hx=lamda[j][k][m]*((rhol-rhog)/(phil-phig))*(DTx*Dphix+DTy*Dphiy+DTz*Dphiz)/(rho[j][k][m]*rho[j][k][m]*ca);
					HH=w1[i]*(dTuxy);
					F[j][k][m][i]= (1.0-ww_f)*f[j][k][m][i] + ww_f*feq(ux[j][k][m], uy[j][k][m],uz[j][k][m], phi[j][k][m], i)+dt*w1[i]*dphiuxyz*rcs1*(1.0-0.5*ww_f)+w1[i]*B[j][k][m]*rcs1*ww_f*FF/dt;
					H[j][k][m][i]= (1.0-ww_h[j][k][m])*h[j][k][m][i] + ww_h[j][k][m]*heq(ux[j][k][m], uy[j][k][m], uz[j][k][m],T[j][k][m], i) + dt*HH;
				}
               
				for(i=0; i<15; i++)
				{  
					wu=weq(ux[j][k][m], uy[j][k][m],uz[j][k][m], i);
					dphiuxyz=e2[i][0]*dphiux+e2[i][1]*dphiuy+e2[i][2]*dphiuz;
									
					Fsx=1.5*D*sigmaT*(Dphixyz*Dphixyz*DTx-(Dphix*DTx+Dphiy*DTy+Dphiz*DTz)*Dphix)+mu[j][k][m]*Dphix;
					Fsy=1.5*D*sigmaT*(Dphixyz*Dphixyz*DTy-(Dphix*DTx+Dphiy*DTy+Dphiz*DTz)*Dphiy)+mu[j][k][m]*Dphiy;
					Fsz=1.5*D*sigmaT*(Dphixyz*Dphixyz*DTz-(Dphix*DTx+Dphiy*DTy+Dphiz*DTz)*Dphiz)+mu[j][k][m]*Dphiz;
					cphix=( (wu-w2[i])*(rhol-rhog) )*Dphix+rcs2*wu*Fsx;
					cphiy=( (wu-w2[i])*(rhol-rhog) )*Dphiy+rcs2*wu*Fsy;
					cphiz=( (wu-w2[i])*(rhol-rhog) )*Dphiz+rcs2*wu*Fsz;
					GG=(c*e2[i][0]-ux[j][k][m])*cphix + (c*e2[i][1]-uy[j][k][m])*cphiy + (c*e2[i][1]-uz[j][k][m])*cphiz+rcs2* wu*( (c*e2[i][0]-ux[j][k][m])*Fn[j][k][m] );////force 
					Fa=rcs2*w2[i]*(e2[i][0]*ux[j][k][m]+e2[i][1]*uy[j][k][m]+e2[i][2]*uz[j][k][m])*(rhol-rhog)*(phi[j][k][m]-phi0[j][k][m]+ux[j][k][m]*Dphix+uy[j][k][m]*Dphiy+uz[j][k][m]*Dphiz);
				
					
					G[j][k][m][i]= (1.0-ww_g[j][k][m])*g[j][k][m][i] + ww_g[j][k][m]*geq(ux[j][k][m], uy[j][k][m], uz[j][k][m], p[j][k][m],  rho[j][k][m], i) + dt*(1-0.5*ww_g[j][k][m])*GG+dt*Fa;
					
				}	
			}
					           
		}
	}

}

void stream()
{
    for(j=0; j<=NY; j++)  //stream
	{
		for(k=0; k<=NX; k++)  
		{
			for(m=0;m<=NX;m++)
			{
				for(i=0; i<7; i++)
				{ 
					jp=j-e1[i][2];
					kp=(k-e1[i][2]+NY)%(NY);
					mp=(m-e1[i][0]+NX)%(NX);
					if(jp>=0&&jp<=NZ)
					{
						f[j][k][m][i]=F[jp][kp][mp][i];						
						h[j][k][m][i]=H[jp][kp][mp][i];
					}
					else if(jp<0)
					{
						f[j][k][m][i]=F[j][k][m][rp1[i]];						
						h[j][k][m][i]=-H[j][k][m][rp1[i]]+2.0*w1[i]*(Th+T00*cos(ww*(k-0.5*NX)));
					}
					else
					{
						f[j][k][m][i]=F[j][k][m][rp1[i]];						
						h[j][k][m][i]=-H[j][k][m][rp1[i]]+2.0*w1[i]*Tc;
					}
				}
				for(i=0; i<15; i++)
				{ 
					jp=j-e2[i][2];
					kp=(k-e2[i][1]+NY)%(NY);
					mp=(k-e2[i][0]+NZ)%(NZ);

					if(jp>=0&&jp<=NZ)
					{
						g[j][k][m][i]=G[jp][kp][mp][i];						
					}
					else if(jp<0)
					{						
						g[j][k][m][i]=G[j][k][m][rp2[i]];						
					}
					else
					{						
						g[j][k][m][i]=G[j][k][m][rp2[i]];						
					}
				}
			}
			
		}
	}
}

void evolution()
{    
	collision();
    stream();

	double mu0, Dphix, Dphiy, Dphiz, DDphi, Fsx, Fsy,Fsz, udphi, UX, UY,UZ;
	double Cx, Cy, Cz,Cxyz,Dphixyz, dphiux, dphiuy,dphiuz;
	double DTx, DTy,DTz, dTux, dTuy,dTuz;
    for(j=0; j<=NZ; j++) //macro calculation
	{
		for(k=0; k<=NY; k++)
		{
			for(m=0; m<=NX; m++)
			{
				T0[j][k][m]=T[j][k][m];
				phi0[j][k][m]=phi[j][k][m];
				ux0[j][k][m]=ux[j][k][m];
				uy0[j][k][m]=uy[j][k][m];
				uz0[j][k][m]=uz[j][k][m];
				phi[j][k][m]=0.0;
				T[j][k][m]=0.0;
				for(i=0;i<7;i++)
				{
					phi[j][k][m]+=f[j][k][m][i];
					T[j][k][m]+=h[j][k][m][i];
				}
				sigma[j][k][m]=sigmaref+sigmaT*(T[j][k][m]-Tref);
				beta[j][k][m]=12*sigma[j][k][m]/(D*(phil-phig)*(phil-phig)*(phil-phig)*(phil-phig));  
				Kappa[j][k][m]=1.5*D*sigma[j][k][m]/((phil-phig)*(phil-phig));
	
				rho[j][k][m]=(phi[j][k][m]-phig)*(rhol-rhog)/(phil-phig)+rhog;
				lamda[j][k][m]=(phi[j][k][m]-phig)*(lamda1-lamda2)/(phil-phig)+lamda2;
				tau_h[j][k][m]=lamda[j][k][m]/(ca*cs1*dt);
				ww_h[j][k][m]=1.0/(tau_h[j][k][m]+0.5);
		  // niu[j][k]=(niu[j][k]-phig)*(niul-niug)/(phil-phig)+niug;	
		  /*  niu[j][k]=(niul*niug*(phil-phig))/((phi[j][k]-phig)*niug+(phil-phi[j][k])*niul);
		   tau_g[j][k]=niu[j][k]*rcs2/dt+0.5;
		   ww_g[j][k]=1.0/tau_g[j][k]; */
		   
				B[j][k][m]=cs1*(tau_f)*dt*4.0*phi[j][k][m]*(1.0-phi[j][k][m])/D;
			}
		}
	}
	
		
	/* for(j=0; j<=NY; j++)
	{
		for(k=0; k<=NX; k++)
		{
			Dphix=Dphiy=0.0;
			for(i=0; i<9; i++)
			{
			   jp=j+e[i][1];
			   kp=(k+e[i][0]+NX1)%(NX1);
			   if(jp>=0&&jp<=NY)
			   {
				    Dphix+=3.0*w[i]*phi[jp][kp]*e[i][0];
					Dphiy+=3.0*w[i]*phi[jp][kp]*e[i][1];
			   }
			   else
			   {
				    Dphix+=3.0*w[i]*phi[j][k]*e[i][0];
					Dphiy+=3.0*w[i]*phi[j][k]*e[i][1];
			   }

			}
			dnx[j][k]=Dphix/sqrt(Dphix*Dphix+Dphiy*Dphiy+exp(-20));
			dny[j][k]=Dphiy/sqrt(Dphix*Dphix+Dphiy*Dphiy+exp(-20));
		}
	} */


	for(j=0; j<=NZ; j++)
	{
	    for(k=0; k<=NY; k++)
		{
			for(m=0;m<=NX;m++)
			{
				DDphi=0.0;
				for(i=1; i<15; i++)
				{
					jp=j+e2[i][2];
					kp=(k+e2[i][1]+NY)%(NY);
					mp=(m+e2[i][0]+NX)%(NX);
				 
					if(jp>=0&&jp<=NZ)
					{
						DDphi+=w2[i]*(phi[jp][kp][mp]-phi[j][k][m]);
					}
					else
					{
						DDphi+=w2[i]*(phi[j][k][m]-phi[j][k][m]);
					}		
				}
				mu0=4.0*beta[j][k][m]*(phi[j][k][m]-phil)*(phi[j][k][m]-phig)*(phi[j][k][m]-phim);
				mu[j][k][m]=mu0-Kappa[j][k][m]*2.0*rcs2*DDphi;
			}			
		}
	}

	for(j=0; j<=NZ; j++)     
	{
		for(k=0; k<=NY; k++)
		{ 
			for(m=0;m<=NX;m++)
			{
				Cx=0.0;
				Cy=0.0;
				Cz=0.0;
				Dphix=Dphiy=Dphiz=0.0;
				DTx=DTy=DTz=0.0;
				dTux=(T[j][k][m]*ux[j][k][m]-T0[j][k][m]*ux0[j][k][m])/dt;
				dTuy=(T[j][k][m]*uy[j][k][m]-T0[j][k][m]*uy0[j][k][m])/dt;
				dTuz=(T[j][k][m]*uz[j][k][m]-T0[j][k][m]*uz0[j][k][m])/dt;
				dphiux=(phi[j][k][m]*ux[j][k][m]-phi0[j][k][m]*ux0[j][k][m])/dt;
				dphiuy=(phi[j][k][m]*uy[j][k][m]-phi0[j][k][m]*uy0[j][k][m])/dt;
				dphiuz=(phi[j][k][m]*uz[j][k][m]-phi0[j][k][m]*uz0[j][k][m])/dt;
				for(i=1; i<7; i++)
				{
					Cx+=e1[i][0]*(f[j][k][m][i]-feq(ux[j][k][m],uy[j][k][m],uz[j][k][m],phi[j][k][m],i));
					Cy+=e1[i][1]*(f[j][k][m][i]-feq(ux[j][k][m],uy[j][k][m],uz[j][k][m],phi[j][k][m],i));
					Cz+=e1[i][2]*(f[j][k][m][i]-feq(ux[j][k][m],uy[j][k][m],uz[j][k][m],phi[j][k][m],i));
				//DTx+=e[i][0]*(h[j][k][i]-heq(u[j][k], v[j][k], T[j][k], i));
				//DTy+=e[i][1]*(h[j][k][i]-heq(u[j][k], v[j][k], T[j][k], i));
				  
				}
				Cx=Cx+0.5*dt*dphiux;
				Cy=Cy+0.5*dt*dphiuy;
				Cz=Cz+0.5*dt*dphiuz; 
				Cxyz=sqrt(Cx*Cx+Cy*Cy+Cz*Cz);
				Dphixyz=-(Cxyz+B[j][k][m])/A;
			 
				Dphix=Cx/(A+(B[j][k][m]/(Dphixyz+exp(-10.0))));
				Dphiy=Cy/(A+(B[j][k][m]/(Dphixyz+exp(-10.0))));
				Dphiz=Cz/(A+(B[j][k][m]/(Dphixyz+exp(-10.0))));
			 /*DTx=(DTx+0.5*dt*dTu)*rcs2*ww_h[j][k]/dt;
			 DTy=(DTy+0.5*dt*dTv)*rcs2*ww_h[j][k]/dt;*/
				for(i=1; i<7; i++)
				{
					jp=j+e1[i][2];
					kp=(k+e1[i][1]+NY)%(NY);
					mp=(m+e1[i][0]+NZ)%(NZ);
					if(jp>=0&&jp<=NZ)
					{
				   /*Dphix+=3.0*w[i]*phi[jp][kp]*e[i][0];
			       Dphiy+=3.0*w[i]*phi[jp][kp]*e[i][1];*/
						DTx+=rcs1*w1[i]*T[jp][kp][mp]*e1[i][0];
						DTy+=rcs1*w1[i]*T[jp][kp][mp]*e1[i][1];
						DTz+=rcs1*w1[i]*T[jp][kp][mp]*e1[i][2];
					}
					else
					{
				   /*Dphix+=3.0*w[i]*phi[j][k]*e[i][0];
			       Dphiy+=3.0*w[i]*phi[j][k]*e[i][1];*/
						DTx+=rcs1*w1[i]*T[j][k][m]*e1[i][0];
						DTy+=rcs1*w1[i]*T[j][k][m]*e1[i][1];
						DTz+=rcs1*w1[i]*T[j][k][m]*e1[i][2];
					}
				}
			//Dphixy=sqrt(Dphix*Dphix+Dphiy*Dphiy);
			
               
			//Dphix=Dphiy=0.0;    //计算Fs,Fa,进一步更新p和u
				UX=UY=UZ=0.0;
				p[j][k][m]=0.0;
				for(i=1; i<15; i++)
				{
			   
					UX+=e2[i][0]*g[j][k][m][i];
					UY+=e2[i][1]*g[j][k][m][i];
					UZ+=e2[i][2]*g[j][k][m][i];
					p[j][k][m]+=g[j][k][m][i];
				}
			  
			   //Fsx=mu[j][k]*Dphix;
			  // Fsy=mu[j][k]*Dphiy;	
				Fsx=1.5*D*sigmaT*(Dphixyz*Dphixyz*DTx-(Dphix*DTx+Dphiy*DTy+Dphiz*DTz)*Dphix)+mu[j][k][m]*Dphix;
				Fsy=1.5*D*sigmaT*(Dphixyz*Dphixyz*DTy-(Dphix*DTx+Dphiy*DTy+Dphiz*DTz)*Dphiy)+mu[j][k][m]*Dphiy;			  
                Fsz=1.5*D*sigmaT*(Dphixyz*Dphixyz*DTz-(Dphix*DTx+Dphiy*DTy+Dphiz*DTz)*Dphiz)+mu[j][k][m]*Dphiz;                      
			  
			   ux[j][k][m]=( UX+0.5*dt*(Fsx+Fn[j][k][m]))/(rho[j][k][m]);
               uy[j][k][m]=( UY+0.5*dt*(Fsy         ))/(rho[j][k][m]);
			   uz[j][k][m]=( UZ+0.5*dt*(Fsz         ))/(rho[j][k][m]);
			   udphi=ux[j][k][m]*Dphix+uy[j][k][m]*Dphiy+uz[j][k][m]*Dphiz;
			   p[j][k][m]=cs2*(p[j][k][m]+0.5*dt*udphi*(rhol-rhog)-0.5*rcs2*rho[j][k][m]*w2[0]*(ux[j][k][m]*ux[j][k][m]+uy[j][k][m]*uy[j][k][m]+uz[j][k][m]*uz[j][k][m]))/(1.0-w2[0]);
		
			}
		 }
	}

}  

 void OutPutData(int t)
 {
	FILE *fp;
	char filename[10];
	int j, k;


    sprintf(filename,"%s","phi");
    fp=fopen(filename,"w");
    for(j=0;j<=NZ;j++)
	{
	    for(k=0;k<=NY;k++)
		{
			for(m=0;m<=NX;m++)
			{
				fprintf(fp,"%lf ",phi[j][k][m]);
				fprintf(fp,"\n");
			}
			
		}
	   
	}
	fclose(fp);
   
	sprintf(filename,"%s","T");
    fp=fopen(filename,"w");
    for(j=0;j<=NZ;j++)
	{
	    for(k=0;k<=NY;k++)
		{
			for(m=0;m<=NX;m++)
			{
				fprintf(fp,"%lf ",T[j][k][m]);
				fprintf(fp,"\n");
			}
		}
	    
	}
	fclose(fp);
	
	sprintf(filename,"%s","u");
    fp=fopen(filename,"w");
    for(j=0;j<=NZ;j++)
	{
	    for(k=0;k<=NY;k++)
		{
			for(m=0;m<=NX;m++)
			{
				fprintf(fp,"%lf ",ux[j][k][m]);
				fprintf(fp,"\n");
			}
		}
	    
	}
	fclose(fp);
	
	sprintf(filename,"%s","uy");
    fp=fopen(filename,"w");
    for(j=0;j<=NZ;j++)
	{
	    for(k=0;k<=NY;k++)
		{
			for(m=0;m<=NX;m++)
			{
				fprintf(fp,"%lf ",uy[j][k][m]);
				fprintf(fp,"\n");
			}
		}
	    
	}
	fclose(fp);

	sprintf(filename,"%s","uy");
    fp=fopen(filename,"w");
    for(j=0;j<=NZ;j++)
	{
	    for(k=0;k<=NY;k++)
		{
			for(m=0;m<=NX;m++)
			{
				fprintf(fp,"%lf ",uz[j][k][m]);
				fprintf(fp,"\n");
			}
		}
	    
	}
	fclose(fp);
 }


void output1(int t)                       //将演化后的每个点的平均速度保存在文件中
{
	FILE *file;

    char name[3000];
	
	sprintf(name,"%s%d%s","result",t,".dat");

    if((file=fopen(name,"w"))==NULL)
	{
		printf(" File Open Error\n");
		exit(1);
	}

//file=fopen("name.dat","w");
fprintf(file,"Title=\"poiseuille flow\"\n");
fprintf(file,"variables=\"x\",\"y\",\"z\",\"ux\",\"uy\",\"uz\"\n");
fprintf(file,"Zone T=\"BOX\",I=%d,J=%d\n",NZ+1,NY+1,NX+1);


	for(k=0;k<=NZ;k++)
	{
		for(j=0;j<=NY;j++)
		{
			for(m=0;m<=NX;m++)
			{
				fprintf(file,"%d,%d,%d,%lf,%lf,%lf\n",k,j,m,ux[j][k][m],uy[j][k][m],uz[j][k][m]);
			}			
		}
	}

	fclose(file);
}

