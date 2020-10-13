#include <stdio.h>

struct Frame{
    int page;
    int age;
};

int main(){
    int n;
    scanf("%d", &n);
    struct Frame frames[n];
    FILE *in = fopen("Lab 09 input.txt", "r");
    int pageId;
    float counter = 0;
    float hit = 0;
    
    //Shows what is the frame number of the given page (-1 means it has no page frame)
    int page[1000]; 
    for(int i = 0; i < 1000; i++){
        page[i] = -1;
    }
    int frameCounter = 0;
    while(fscanf(in, "%d", &pageId)!= EOF){
        counter++;
        if(page[pageId] == -1){
            if(frameCounter == n){
                int mn = 10000;
                int ind = 0;
                for(int i = 0; i < n; i++){
                    if(frames[i].age < mn){
                        mn = frames[i].age;
                        ind = i;
                    }
                } 
                page[frames[ind].page] = -1;
                frames[ind].page = pageId;
                frames[ind].age = 0;
                page[pageId] = ind;
            }
            else{
                frames[frameCounter].page = pageId;
                frames[frameCounter].age = 0;
                page[pageId] = frameCounter;
                frameCounter++;
            }
        }
        else{
            hit++;
        }
        for(int i = 0; i < n; i++){
            if(pageId == frames[i].page){
                frames[i].age = (frames[i].age>>1)|(1<<31);
            }
            else{
                frames[i].age = (frames[i].age>>1);
            }
        }
    }
    fclose(in);
    printf("Hit ratio: %f\n", hit/counter);
    printf("Miss ratio: %f\n", 1 - hit/counter);
    printf("Hit/Miss ratio: %f\n", hit/(counter - hit));
}
/*
10 frames:
Hit ratio: 0.009000
Miss ratio: 0.991000
Hit/Miss ratio: 0.009082

50 frames:
Hit ratio: 0.050000
Miss ratio: 0.950000
Hit/Miss ratio: 0.052632

100 frames:
Hit ratio: 0.093000
Miss ratio: 0.907000
Hit/Miss ratio: 0.102536
*/