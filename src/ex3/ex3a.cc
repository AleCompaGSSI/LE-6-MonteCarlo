#include "utils.h"
#include "point.h"

#include <random>
#include <iostream>

void plot_graph(int N, double x[], double y[]){

    TCanvas *c = new TCanvas();
    TGraph* gr = new TGraph(N, x, y);

    gr->SetLineWidth(2);
    gr->GetXaxis()->SetTitle("N_{points}");
    gr->GetXaxis()->SetTitleSize(0.05);
    gr->GetXaxis()->SetLabelSize(0.05);
    gr->GetYaxis()->SetTitle("#pi - #pi_{est}");
    gr->GetYaxis()->SetTitleSize(0.05);
    gr->GetYaxis()->SetLabelSize(0.05);

    gr->SetTitle("#pi vs. MC estimate");
    gr->GetXaxis()->SetRangeUser(1,10000);
    gr->GetYaxis()->SetRangeUser(-0.2,0.2);


    gr->Draw("AL");

    c->SetLeftMargin(0.15);
    c->SetBottomMargin(0.15);

    c->SetGrid();

    c->Print("pi.pdf");

}

int main(){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);

    int inside = 0;
    int tot = 0;

    int N = 2000;

    double x[N],y[N];
    
    for(size_t i = 0; i<N*5; i++){
        Point p = rand_in_unit_square(distr, mt);
        if( (p.x*p.x + p.y*p.y) < 1.0) inside++; 
        tot ++;
        if (tot % 5 == 0) {
            x[i/5] = (double) tot;
            y[i/5] = M_PI - 4.0 *  (double) inside / (double)tot;
            //std::cout << tot << std::setprecision(10) <<" " << (M_PI - 4.0 *  (double) inside / (double)tot) << std::endl;
        }
    }
    plot_graph(N, x, y);

}