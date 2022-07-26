/*
const fib=(n)=>{
    if(n<=2) return 1;
    console.log("\t",n);
    return fib(n-1)+fib(n-2);
}
console.log("Answer :",fib(10));

class ListNode {
    constructor(val){
        this.val=val;
        this.next=null;
    }
}
*/
let ListNode=(val)=>{
    this.val=val;
    this.next=null;
}

var head=new ListNode(34);
var second=new ListNode(45);
head.next=second;
var third=new ListNode(90);
second.next=third;
third.next=null;

var p=head;

while(p!=null){
    console.log(p.val);
    p=p.next;
}
