class Node{
    constructor(element){
        this.element = element;
        this.left = null;
        this.right = null;
    }
}
class BinaryTree{
    constructor(element){
        var root = new Node(element);
        return root;
    }
}
function add(root,element){
    if(root == null) root = new Node(element);
    if(element<root.element)
    {
        add(root.left,element);
    }else if(element>root.element){
        add(root.right,element);
    }
}
function inorder(root){
    if(root!=null){
        inorder(root.left);
        console.log(`${root.element} `);
        inorder(root.right);
    }
}
var root = new Node(10);
root.left = new Node(6);
root.right = new Node(15);
console.log(root.right.element);
inorder(root);
/*class LinkedList{
    constructor(){
        this.head = null;
        this.size = 0;
    }
    add(element){
        var node = new Node(element);
        if(this.head == null){
            this.head = node;
        }else{
            let curr;
            curr = this.head;
            while(curr.next != null) curr = curr.next;
            curr.next = node;
             
            this.size++;
        }
    }
    display(){
        let curr = this.head,i=0;
        while(curr) {
            console.log(`${i++})=>${curr.element}`)
            curr = curr.next;
        };
    }
    insertAt(element,index){
        if(index<0) console.log("Please provide valid index");
        var i=1,curr = this.head;
        if(index == 0){
            var node = new Node(element);
            node.next = this.head;
            this.head = node;
        }else{   
            while(curr != null && i != index){
                curr = curr.next;
                i++;
            }
            if(i==index){
                let temp = curr.next;
                var node = new Node(element);
                curr.next = node;
                node.next = temp;
            }else{
                console.log("Index not Found");
            }   
        }
    }
}

custom_list = new LinkedList();
custom_list.add(5);
custom_list.add(0);
custom_list.add(8);
custom_list.add(45);
custom_list.add(89);

custom_list.insertAt(4,5);
custom_list.display();*/