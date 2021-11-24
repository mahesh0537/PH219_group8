void plot(){
    TFile *f= new TFile("data.root");
    TTree *tree = (TTree*)f->Get("pytree100;3");
    
    
    const Int_t maxTrack=10000;
    Int_t ntrack = 0;
    Double_t pT[maxTrack];
    Double_t eta[maxTrack];
    Double_t rap[maxTrack];
    Double_t phi[maxTrack];


    tree->SetBranchAddress("ntrack",&ntrack);
    tree->SetBranchAddress("phi",&phi);
    tree->SetBranchAddress("pT",&pT);
    tree->SetBranchAddress("eta",&eta);

    Int_t nenteries = (Int_t)tree->GetEntries();


    TH1D *mult = new TH1D("mult1003","multiplicity",100,-1.0,350.0);
    TH1D *mult1 = new TH1D("mult10031","multiplicity",100,-1.0,350.0);


    for(Int_t i = 0; i < nenteries; i++){
        tree->GetEntry(i);
        int count = 0;
        for(int i = 0; i < ntrack; i++){
            if ((eta[i] < 1.0 && eta[i] > -1.0) && pT[i] > 0.05){
                count += 1;
            }
        }
        mult->Fill(count);
        mult1->Fill(ntrack);
    }
    //TFile *result = new TFile("result.root", "recreate");
    //TFile *result = new TFile("result.root", "update");
    //mult->Write();
    //result->Close();
    mult1->Draw();
    //mult->Draw();
}