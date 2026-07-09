from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Book(BaseModel):
    id: int
    title: str
    author: str
    price: int


@app.get("/")
def home():
    return {"message": "Welcome to the Book API"}


books = [{"id": 1, "title": "Clean Code", "author": "Robert Martin", "price": 799}]


@app.get("/books")
def getBook():
    return books


@app.get("/books/{id}")
def getBookById(bookid: int):
    for book in books:
        if book["id"] == bookid:
            return book


@app.post("/books")
def addBooks(book: Book):
    books.append(
        {
            "id": len(books) + 1,
            "title": book.title,
            "author": book.author,
            "price": book.price,
        }
    )


@app.put("/books/{id}")
def update_book(book_id: int, book: Book):
    for b in books:
        if b["id"] == book_id:
            b["title"] = book.title
            b["author"] = book.author
            b["price"] = book.price
            return {"message": "Book updated", "book": b}
        
   
        
@app.delete("/books/{id}")
def update_book(book_id: int, book: Book):
    for b in books:
        
        if book["id"] == book_id:
            deleted_book = books.pop(i)
            return {
                "message": "Book deleted successfully",
                "book": deleted_book
            }
        
        