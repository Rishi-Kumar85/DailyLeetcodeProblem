int longestMonotonicSubarray(int* nums, int numsSize) {
    int maxlength = 1;
    int length = 1;
    for(int i = 0 ; i<numsSize-1;i++){
        if(nums[i+1]>nums[i]){
            length++;
        }
        else{
            length = 1;
        }
   
        if(length>maxlength){
            maxlength = length;
        }
    }
    length = 1;
    for(int i = 0 ; i<numsSize-1;i++){
        if(nums[i+1]<nums[i]){
            length++;
        }
        else{
            length = 1;
        }
   
        if(length>maxlength){
            maxlength = length;
        }
    }
    return maxlength;
}