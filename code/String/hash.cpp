for (int i=1;i<=L;i++) Hash[i]=(Hash[i-1]*Hashbase%Mod+str[i])%Mod;
for (int i=1;i<=L;i++){
    Hash[i]=(Hash[i-1]*Hashbase%Mod+str[i])%Mod;
    Hashbase=Hashbase*Hashbase%Mod;
}
for (int i=1;i<=L;i++) Hash[i]=(Hash[i-1]<<5)^(Hash[i-1]>>27)^str[i]);
