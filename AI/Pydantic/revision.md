# Pydantic
## 1. LLMs are probabilistic, not guaranteed

    An LLM can return:

    Missing fields
    Wrong types
    Invalid values
    Unexpected formats

    Never assume the output is always correct.

## 2. Pydantic is a validation layer

    Its job is to:

    Parse data
    Convert compatible types
    Validate values
    Reject invalid input before business logic runs


## 3. Validation comes before business logic

### The ideal flow is:
    User / API / LLM
        ↓
    Raw JSON
        ↓
    Pydantic Validation
        ↓
    Validated Python Object
        ↓
    Business Logic
        ↓
    Database / Tool Call / Response