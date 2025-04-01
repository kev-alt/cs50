from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    conn = sqlite3.connect("birthdays.db")
    db = conn.cursor()

    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        if name and month and day:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", (name, month, day))
            conn.commit()

        return redirect("/")

    db.execute("SELECT * FROM birthdays")
    birthdays = db.fetchall()
    conn.close()

    return render_template("index.html", birthdays=birthdays)

@app.route("/delete/<int:id>", methods=["POST"])
def delete(id):
    conn = sqlite3.connect("birthdays.db")
    db = conn.cursor()
    db.execute("DELETE FROM birthdays WHERE id = ?", (id,))
    conn.commit()
    conn.close()
    return redirect("/")
