class heap{
public:
    state H[maxH];int c;
    void push(state x){
	H[++c]=x;push_heap(&H[1],&H[c+1]);
    }
    state top(){
	return H[1];
    }
    void pop(){
	pop_heap(&H[1],&H[c+1]);--c;
    }
    bool empty(){
	return c==0;
    }
};
