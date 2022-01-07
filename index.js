'use strict';

const taskBtn = document.querySelector(".addTaskBtn");
let taskInputBox = document.querySelector(".taskInput");
let submitInputBtn = document.querySelector("[type='submit']");
let dateInput = document.querySelector("#taskDate");
let tasks = document.querySelector(".taskList");
let taskContainer = document.querySelector(".tasks");
let inputContainer = document.querySelectorAll("input");
let textInputValue;
let dateInputValue;
const localStorageTodos = JSON.parse(localStorage.getItem("todos"));

document.addEventListener("DOMContentLoaded", function(){
    let textInput = document.querySelector("#taskToDo");

    if(localStorageTodos){
        localStorageTodos.forEach(element => {
            addToList(element);
        });
    }
    
    taskBtn.addEventListener("click", function(){
        taskInputBox.classList.toggle("toggleDisplay");
    })
    
    dateInput.addEventListener("change", function(){
        dateInputValue = this.valueAsDate;
    })
    
    textInput.addEventListener("keyup", function(){
        textInputValue = this.value;
    })
    
    submitInputBtn.addEventListener("click", function(e){
        e.preventDefault();
        if(textInput.value === "" || textInput <= 0){
            alert("Please enter a task.");
            resetValues();
        }
        else if(dateInputValue === undefined){
            alert("Please enter a date");
        }
        else{
            dateInputValue = dateInputValue.toUTCString().split(' ').slice(0, 4).join(' ');
            textInputValue = textInputValue + " by " + dateInputValue;
            addToList();
        }
    })
    
    function addToList(todo){
    
        let checkButton = document.createElement("i");
    
        taskContainer.style.display = "block";
        checkButton.style.display = "inline";
    
        checkButton.setAttribute("class", "fas fa-check");
    
        if(todo){
            textInputValue = todo.text;
        }
    
        if(textInputValue){
            const li = document.createElement("li");
            if(todo && todo.completed){
                li.classList.toggle("completed");
            }
    
            tasks.appendChild(li);
            li.innerText = textInputValue;
    
            li.addEventListener("dblclick", function(){
                li.remove();
                checkButton.remove();
                
                toLocalStorage();
            })
    
            checkButton.addEventListener("click", function(){
                    li.classList.toggle("completed");
        
                    toLocalStorage();
            })
        }
    
        tasks.appendChild(checkButton);
    
        resetValues();
    
        toLocalStorage();
    }
    
    function toLocalStorage() {
        const liElement = document.querySelectorAll("li");
        const todos = [];
    
        if(tasks.childElementCount == 1){
            taskContainer.classList.add("toggleDisplay");
        }
        else {
            taskContainer.classList.remove("toggleDisplay");
        }
    
        liElement.forEach(liEle => {
            todos.push({
                text: liEle.innerText,
                completed: liEle.classList.contains("completed"),
            });
        });
    
        localStorage.setItem("todos", JSON.stringify(todos));
    
    
    }
    
    function resetValues() {
        textInputValue = "";
        dateInputValue = undefined;
    
        inputContainer.forEach(element => {
            element.value = "";
        });
    }
})



