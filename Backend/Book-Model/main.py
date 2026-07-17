from fastapi import FastAPI , HTTPException
from pydantic import BaseModel , Field
from datetime import datetime

app = FastAPI()

class Book(BaseModel):
    
    title: str
    author: str
    price: int=Field(gt=0, description="Price must be greater than zero")

books = [
    {
        "id":1,
        "title":"Clean Code",
        "author":"Robert Martin",
        "price":799
    }
]


@app.get("/")
def home():
    return {"message": "Welcome to the Book API"}



@app.get("/books")
def getBook():
    return books


from datetime import datetime

@app.get("/health")
def health():
    return {
        "status": "healthy",
        "service": "Book API",
        "timestamp": datetime.now()
    }
    
@app.get("/books/{id}")
def getBookById(id: int):
    for book in books:
        if book["id"] == id:
            return book
    raise HTTPException(status_code=404, detail="Book not found")


#search book by author

@app.get("/books/author")
def getBookByAuthor(author: str):
    result = []
    for book in books:
        if book["author"].lower() == author.lower():
            result.append(book)
    if not result:
        raise HTTPException(status_code=404, detail="No books found by this author")
    return result


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
def update_book(id: int, book: Book):
    for b in books:
        if b["id"] == id:
            b["title"] = book.title
            b["author"] = book.author
            b["price"] = book.price
            return {"message": "Book updated", "book": b}
    
    raise HTTPException(status_code=404, detail="Book not found")
        
   
        
@app.delete("/books/{id}")
def update_book(id: int, book: Book):
    for b in books:
        
        if book["id"] == id:
            deleted_book = books.pop(i)
            return {
                "message": "Book deleted successfully",
                "book": deleted_book
            }
            
    raise HTTPException(status_code=404, detail="Book not found")
        
        
        
@app.get("/books/count")
def books_count(book:Book):
    return len(books)